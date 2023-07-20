//
//  TsetSApp.swift
//  TsetS
//
//  Created by Ben on 2023/4/29.
//

import SwiftUI

@main
struct TsetSApp: App {
    var body: some Scene {
        DocumentGroup(newDocument: TsetSDocument()) { file in
            ContentView(document: file.$document)
        }
    }
}
