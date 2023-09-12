//
//  RegistrationVM.swift
//  PorscheHomework
//
//  Created by Ben on 2023/9/6.
//

import Foundation

class RegistrationVM {
    var user: User
    
    init(user: User) {
        self.user = user
    }
    
    func signUp(completionHandler: @escaping (User?, Error?) -> Void) {
        AccountServices.signUp(user, completionHandler: completionHandler)
    }
}




