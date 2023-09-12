//
//  InputCell.swift
//  PorscheHomework
//
//  Created by Ben on 2023/9/5.
//

import Foundation
import UIKit
import Combine

class InputCell: UITableViewCell {
    @IBOutlet weak var label: UILabel?
    @IBOutlet weak var inputTextField: UITextField?
    
    var infoType: InfoType = InfoType.firstName
    var user: User?
    var cancellable: Cancellable?
    
    func set(infoType type: InfoType, user userInfo: User) {
        infoType = type
        user = userInfo
        
        switch infoType {
        case .avator:
            assert(false)
        case .customAvatorColor:
            assert(false)
        case .signUpButton:
            assert(false)
        case .firstName:
            self.label?.text = "First Name"
            self.inputTextField?.textContentType = UITextContentType.name
            
            cancellable = self.inputTextField?.publisher(for: \.text).sink(receiveValue: { text in
                self.user?.firstName = text
            })
        case .lastName:
            self.label?.text = "Last Name"
            self.inputTextField?.textContentType = UITextContentType.name
            
            cancellable = self.inputTextField?.publisher(for: \.text).sink(receiveValue: { text in
                self.user?.lastName = text
            })
        case .phoneNumber:
            self.label?.text = "Phone Number"
            self.inputTextField?.textContentType = UITextContentType.telephoneNumber
            
            cancellable = self.inputTextField?.publisher(for: \.text).sink(receiveValue: { text in
                self.user?.phoneNumber = text
            })
        case .email:
            self.label?.text = "Email"
            self.inputTextField?.textContentType = UITextContentType.emailAddress
            
            cancellable = self.inputTextField?.publisher(for: \.text).sink(receiveValue: { text in
                self.user?.email = text
            })
        }
    }
}




