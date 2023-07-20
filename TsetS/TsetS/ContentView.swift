//
//  ContentView.swift
//  TsetS
//
//  Created by Ben on 2023/4/29.
//

import SwiftUI

struct ContentView: View {
    @Binding var document: TsetSDocument

    var body: some View {
        TextEditor(text: $document.text)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView(document: .constant(TsetSDocument()))
    }
}
