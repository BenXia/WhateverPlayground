//
//  AvatorBorderColorCell.swift
//  PorscheHomework
//
//  Created by Ben on 2023/9/5.
//

import Foundation
import UIKit

//@objc class AvatorBorderColorCell: UITableViewCell, UIColorPickerViewControllerDelegate {
//
//    var parentVC: UIViewController?
//    //@Published var borderColor: UIColor?
//    @objc dynamic var borderColor: UIColor?
//
//    @IBAction func didClickSelectColor(_ sender: Any) {
//        let vc: UIColorPickerViewController = UIColorPickerViewController()
//        vc.selectedColor = self.borderColor ?? UIColor.blue
//        vc.delegate = self
//        parentVC?.present(vc, animated: true)
//    }
//
//    func colorPickerViewController(_ viewController: UIColorPickerViewController, didSelect color: UIColor, continuously: Bool) {
//        self.borderColor = color
//    }
//}

class AvatorBorderColorCell: UITableViewCell, UIColorPickerViewControllerDelegate, ObservableObject {
    
    var parentVC: UIViewController?
    @Published var borderColor: UIColor?
    //@objc dynamic var borderColor: UIColor?
    
    @IBAction func didClickSelectColor(_ sender: Any) {
        let vc: UIColorPickerViewController = UIColorPickerViewController()
        vc.selectedColor = self.borderColor ?? UIColor.blue
        vc.delegate = self
        parentVC?.present(vc, animated: true)
    }
    
    func colorPickerViewController(_ viewController: UIColorPickerViewController, didSelect color: UIColor, continuously: Bool) {
        self.borderColor = color
    }
}




