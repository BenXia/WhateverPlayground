//
//  RegistrationVC.swift
//  PorscheHomework
//
//  Created by Ben on 2023/9/4.
//

import UIKit
import Combine

enum InfoType {
    case avator
    case firstName
    case lastName
    case phoneNumber
    case email
    case customAvatorColor
    case signUpButton
}

struct CellInfo: Hashable {
    var infoType: InfoType
    let identifier = UUID()

    func hash(into hasher: inout Hasher) {
        hasher.combine(identifier)
    }

    static func ==(lhs: CellInfo, rhs: CellInfo) -> Bool {
        return lhs.identifier == rhs.identifier
    }
}

enum Section: CaseIterable {
    case profile
}

class RegistrationVC: UIViewController {
    @IBOutlet weak var tableView: UITableView!
    
    var dataSource: UITableViewDiffableDataSource<Section, CellInfo>!
    var viewModel: RegistrationVM = {
        RegistrationVM.init(user: User.init())
    }()
    
    var cancellableA: Cancellable?
    var cancellableB: Cancellable?
    var cancellableC: Cancellable?
    var cancellableD: Cancellable?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.backgroundColor = UIColor.lightGray
    
        dataSource = getDataSource()
        tableView.dataSource = dataSource
        
        let cellInfoList = [
            CellInfo(infoType: InfoType.avator),
            CellInfo(infoType: InfoType.firstName),
            CellInfo(infoType: InfoType.lastName),
            CellInfo(infoType: InfoType.phoneNumber),
            CellInfo(infoType: InfoType.email),
            CellInfo(infoType: InfoType.customAvatorColor),
            CellInfo(infoType: InfoType.signUpButton)
        ]

        updateData(cellInfoList)
    }
    
    func getDataSource() -> UITableViewDiffableDataSource<Section, CellInfo>! {
        var dataSource = UITableViewDiffableDataSource<Section, CellInfo>(tableView: tableView) {
                [weak self] (tableView: UITableView, indexPath: IndexPath, cellInfo: CellInfo) -> UITableViewCell? in
            guard let `self` = self else { return nil }
            
            switch cellInfo.infoType {
                case InfoType.avator:
                let cell: AvatorCell = tableView.dequeueReusableCell(withIdentifier: "avatorCell", for: indexPath) as! AvatorCell
                cell.parentVC = self
                cell.borderColor = self.viewModel.user.customAvatorColor
                cell.avatorImage = self.viewModel.user.avator
//                cancellableA = self.viewModel.user.publisher(for: \.customAvatorColor)
//                .receive(on: DispatchQueue.main).sink { [weak self] _ in
//                    cell.borderColor = self?.viewModel.user.customAvatorColor
//                }
                cancellableA = self.viewModel.user.publisher(for: \.customAvatorColor)
                .receive(on: DispatchQueue.main).assign(to: \.borderColor, on: cell)

//                cancellableA = self.viewModel.user.$customAvatorColor.receive(on: DispatchQueue.main).assign(to: \.borderColor, on: cell)
                                
//                cancellableB = cell.publisher(for: \.avator)
//                .sink(receiveValue: { [weak self] _ in
//                    self?.viewModel.user.avator = cell.avator
//                })
                cancellableB = cell.$avator.sink{ [weak self] avator in
                    self?.viewModel.user.avator = avator
                }
                
                return cell
                    
                case InfoType.firstName:
                let cell: InputCell = tableView.dequeueReusableCell(withIdentifier: "inputCell", for: indexPath) as! InputCell
                cell.set(infoType:InfoType.firstName, user: self.viewModel.user)
                return cell
            
                case InfoType.lastName:
                let cell: InputCell = tableView.dequeueReusableCell(withIdentifier: "inputCell", for: indexPath) as! InputCell
                cell.set(infoType:InfoType.lastName, user: self.viewModel.user)
                return cell
                    
                case InfoType.phoneNumber:
                let cell: InputCell = tableView.dequeueReusableCell(withIdentifier: "inputCell", for: indexPath) as! InputCell
                cell.set(infoType:InfoType.phoneNumber, user: self.viewModel.user)
                return cell
                
                case InfoType.email:
                let cell: InputCell = tableView.dequeueReusableCell(withIdentifier: "inputCell", for: indexPath) as! InputCell
                cell.set(infoType:InfoType.email, user: self.viewModel.user)
                return cell
                
                case InfoType.customAvatorColor:
                let cell: AvatorBorderColorCell = tableView.dequeueReusableCell(withIdentifier: "avatorBorderColorCell", for: indexPath) as! AvatorBorderColorCell
                cell.parentVC = self
//                cancellableC = cell.publisher(for: \.borderColor).sink { [weak self] color in
//                    self?.viewModel.user.customAvatorColor = color
//                }
                cancellableC = cell.$borderColor.sink { [weak self] color in
                    self?.viewModel.user.customAvatorColor = color
                }
                               
                return cell
                
                case InfoType.signUpButton:
                let cell: SignUpCell = tableView.dequeueReusableCell(withIdentifier: "signUpCell", for: indexPath) as! SignUpCell
                cell.signUpCallBack = { [weak self] in
                    self?.viewModel.signUp(completionHandler: { user, error in
                        if let `error` = error {
                            // TODO: show the error tips to user with UIAlertViewController
                            
                            return
                        } else if let postUser = user {
                            self?.viewModel.user = postUser
                        }
                    })
                }
                
                // ⚠️：这种写法可以在事件触发时候，model 里面的值已经更新
                cancellableD = Publishers.CombineLatest(Publishers.CombineLatest4(
                    self.viewModel.user.publisher(for: \.avator),
                    self.viewModel.user.publisher(for: \.firstName),
                    self.viewModel.user.publisher(for: \.lastName),
                    self.viewModel.user.publisher(for: \.phoneNumber)),
                    self.viewModel.user.publisher(for: \.email)
                ).map{ [weak self] _ in
                    guard let `self` = self else { return false }

                    guard let _ = self.viewModel.user.avator else { return false }
                    guard let firstName = self.viewModel.user.firstName  else { return false }
                    if firstName.count == 0 { return false }

                    guard let lastName = self.viewModel.user.lastName else { return false }
                    if lastName.count == 0 { return false }

                    guard let phoneNumber = self.viewModel.user.phoneNumber else { return false }
                    if phoneNumber.count == 0 { return false }

                    guard let email = self.viewModel.user.email else { return false }
                    if email.count == 0 { return false }

                    return true
                
//                cancellableD = Publishers.CombineLatest(
//                    self.viewModel.user.$avator,
//                    Publishers.CombineLatest4(
//                        self.viewModel.user.$firstName,
//                        self.viewModel.user.$lastName,
//                        self.viewModel.user.$phoneNumber,
//                        self.viewModel.user.$email).map({ _firstName, _lastName, _phoneNumber, _email in
//                            if _firstName != nil && _firstName!.count > 0 &&
//                               _lastName != nil && _lastName!.count > 0 &&
//                               _phoneNumber != nil && _phoneNumber!.count > 0 &&
//                               _email != nil && _email!.count > 0 {
//                                return true
//                            } else {
//                                return false
//                            }
//                        })
//                ).map{ [weak self] (avator, valid) in
//
//                    if avator != nil && valid {
//                        return true
//                    } else {
//                        return false
//                    }
                
                // ⚠️：这种写法不行，事件触发时候，model 里面的值还可能没更新
//                cancellableD = self.viewModel.user.$avator.combineLatest(self.viewModel.user.$firstName)
//                    .combineLatest(self.viewModel.user.$lastName)
//                    .combineLatest(self.viewModel.user.$phoneNumber)
//                    .combineLatest(self.viewModel.user.$email
//                ).map{ [weak self] _ in
//                    guard let `self` = self else { return false }
//
//                    guard let _ = self.viewModel.user.avator else { return false }
//                    guard let firstName = self.viewModel.user.firstName  else { return false }
//                    if firstName.count == 0 { return false }
//
//                    guard let lastName = self.viewModel.user.lastName else { return false }
//                    if lastName.count == 0 { return false }
//
//                    guard let phoneNumber = self.viewModel.user.phoneNumber else { return false }
//                    if phoneNumber.count == 0 { return false }
//
//                    guard let email = self.viewModel.user.email else { return false }
//                    if email.count == 0 { return false }
//
//                    return true
                    
                
//                cancellableD = self.viewModel.user.$avator.combineLatest(self.viewModel.user.$firstName)
//                        .map({ avator, firstName in
//                        if avator != nil && firstName != nil && firstName!.count > 0 {
//                            return true
//                        } else {
//                            return false
//                        }
//                    })
//                    .combineLatest(self.viewModel.user.$lastName)
//                    .map({ (valid: Bool, lastName) in
//                        if valid && lastName != nil && lastName!.count > 0 {
//                            return true
//                        } else {
//                            return false
//                        }
//                    })
//                    .combineLatest(self.viewModel.user.$phoneNumber)
//                    .map({ (valid: Bool, phoneNumber) in
//                        if valid && phoneNumber != nil && phoneNumber!.count > 0 {
//                            return true
//                        } else {
//                            return false
//                        }
//                    })
//                    .combineLatest(self.viewModel.user.$email)
//                        .map{ (valid: Bool, email) in
//                        if valid && email != nil && email!.count > 0 {
//                            return true
//                        } else {
//                            return false
//                        }
//                ).map{ [weak self] _ in

                }.receive(on: DispatchQueue.main)
//                .sink{ enabled in
//                    cell.buttonEnabled = enabled
//               }
                .sink{
                    cell.buttonEnabled = $0
                }
                
                return cell
            }
        }
        
        dataSource.defaultRowAnimation = UITableView.RowAnimation.fade
        return dataSource
    }
    
    func updateData(_ cellInfoList: [CellInfo]) {
        var snapshot = NSDiffableDataSourceSnapshot<Section, CellInfo>()
        snapshot.appendSections([Section.profile])
        snapshot.appendItems(cellInfoList)
        self.dataSource.apply(snapshot, animatingDifferences: false, completion: nil)
    }
}

extension RegistrationVC: UITableViewDelegate {
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        let cellInfo: CellInfo = dataSource.snapshot().itemIdentifiers(inSection: Section.profile)[indexPath.row]
    
        switch cellInfo.infoType {
        case .avator:
            return 100
        case .signUpButton:
            return 80
        case .firstName:
            fallthrough
        case .lastName:
            fallthrough
        case .phoneNumber:
            fallthrough
        case .email:
            fallthrough
        case .customAvatorColor:
            return 70
        }
    }
}




