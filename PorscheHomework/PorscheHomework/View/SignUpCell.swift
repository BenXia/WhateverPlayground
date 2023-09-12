//
//  SignUpCell.swift
//  PorscheHomework
//
//  Created by Ben on 2023/9/5.
//

import Foundation
import UIKit

class SignUpCell: UITableViewCell, ObservableObject {
    @IBOutlet weak var signUpButton: UIButton?
    
    @Published var buttonEnabled: Bool = false {
        didSet {
            self.signUpButton?.isEnabled = buttonEnabled
        }
    }
    
    var signUpCallBack: (() -> Void)?
    
    @IBAction func didClickSignUpButton(_ sender: Any) {
        if let signUpAction = signUpCallBack {
            signUpAction()
        }
    }
}




