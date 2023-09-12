//
//  User.swift
//  PorscheHomework
//
//  Created by Ben on 2023/9/5.
//

import Foundation
import UIKit

@objc class User: NSObject {
    var userId: NSString?          // exist post sign up
    var avatorImageUrl: NSString?  // exist post sign up
    var customAvatorColorHexString: NSString?  // exist post sign up

    @objc dynamic var avator: UIImage?
    @objc dynamic var firstName: String?
    @objc dynamic var lastName: String?
    @objc dynamic var phoneNumber: String?
    @objc dynamic var email: String?
    @objc dynamic var customAvatorColor: UIColor? = UIColor.blue
}

//class User: ObservableObject {
//    var userId: NSString?          // exist post sign up
//    var avatorImageUrl: NSString?  // exist post sign up
//    var customAvatorColorHexString: NSString?  // exist post sign up
//    
//    @Published var avator: UIImage?
//    @Published var firstName: String?
//    @Published var lastName: String?
//    @Published var phoneNumber: String?
//    @Published var email: String?
//    @Published var customAvatorColor: UIColor? = UIColor.blue
//}




