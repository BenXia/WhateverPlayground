//
//  AvatorCell.swift
//  PorscheHomework
//
//  Created by Ben on 2023/9/5.
//

import Foundation
import UIKit
import PhotosUI

//@objc class AvatorCell: UITableViewCell, PHPickerViewControllerDelegate {
//    @IBOutlet weak var avatorImageView: UIImageView?
//    @objc dynamic var avator: UIImage?

class AvatorCell: UITableViewCell, PHPickerViewControllerDelegate, ObservableObject {
    @IBOutlet weak var avatorImageView: UIImageView?
    @Published var avator: UIImage?
    
    var parentVC: UIViewController?
    
    var borderColor: UIColor? {
        didSet {
            self.avatorImageView?.layer.borderColor = borderColor?.cgColor
        }
    }
    var avatorImage: UIImage? {
        didSet {
            self.avator = avatorImage
            self.avatorImageView?.image = avatorImage
        }
    }
    
    @IBAction func didClickSelectAvator(_ sender: Any) {
        var configuration: PHPickerConfiguration = PHPickerConfiguration.init()
        configuration.selectionLimit = 1
        configuration.filter = PHPickerFilter.images
        configuration.preferredAssetRepresentationMode = PHPickerConfiguration.AssetRepresentationMode.current
        let vc = PHPickerViewController.init(configuration: configuration)
        vc.delegate = self
        vc.modalPresentationStyle = UIModalPresentationStyle.fullScreen
        parentVC?.present(vc, animated: true)
    }
    
    func picker(_ picker: PHPickerViewController, didFinishPicking results: [PHPickerResult]) {
        if let result = results.first {
            if result.itemProvider.canLoadObject(ofClass: UIImage.self) {
                result.itemProvider.loadObject(ofClass: UIImage.self) { [weak self] object, error in
                    if let `error` = error {
                        // TODO: show the error tips to user with UIAlertViewController
                        DispatchQueue.main.async {
                            picker.dismiss(animated: true)
                        }
                        
                        return
                    } else {
                        DispatchQueue.main.async {
                            self?.avatorImage = object as! UIImage
                            
                            picker.dismiss(animated: true)
                        }
                    }
                }
            }
        } else {
            DispatchQueue.main.async {
                picker.dismiss(animated: true)
            }
            
            return
        }
    }
}



