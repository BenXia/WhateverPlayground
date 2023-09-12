//
//  RegistrationServices.swift
//  PorscheHomework
//
//  Created by Ben on 2023/9/6.
//

import Foundation
import UIKit

class AccountServices {
    static func signUp(_ user: User, completionHandler: @escaping (User?, Error?) -> Void) {
        // Mock without call async network component api
        // just call completionHandler directly for demo
        
        DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + 3.0) {
            let postUser = User.init()
            postUser.userId = "007"
            postUser.avatorImageUrl = "https://assets-v2.porsche.cn/cn/-/media/Project/PCOM/SharedSite/Banner-Rotation---Archive/911/992-TOP-S-Cab/01---992-TOP-S-Cab.jpg?rev=-1&extension=webp&w=3600&q=65"
            postUser.customAvatorColorHexString = "0xFFFFFFFF"
            postUser.avator = user.avator
            postUser.firstName = user.firstName
            postUser.lastName = user.lastName
            postUser.phoneNumber = user.phoneNumber
            postUser.email = user.email
            postUser.customAvatorColor = user.customAvatorColor
            
            completionHandler(postUser, nil)
        }
    }
}




