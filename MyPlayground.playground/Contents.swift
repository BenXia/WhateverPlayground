import UIKit

var greeting = "Hello, playground"
var str = String(UnicodeScalar(99))
var ch = Character(UnicodeScalar(UInt8(100)))

str.append(ch)

str.unicodeScalars.first?.value == 99
str.unicodeScalars.ranges(of: Collection)

ch.unicodeScalars.first



