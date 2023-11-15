import UIKit

// 预备知识：
// 字符三层编码
// 字符集及码元
// 单个编码码元大小
// 定长或变长码元 <-> 码元的映射规则

// String 不要理解成一个集合类型，可以理解成提供了从多个维度展现unicode视图的类型
// UTF-8 View、UTF-16 View、Scalar View、Character collections
// String.count 与 NSString.length 的差异
// NSString.length 与 NSString.data(using:.utf8).count 的差异
let string: String = "👩‍👩‍👦‍👦"
print("string length: \(string.count)")
print("string.utf16: \(string.utf16)")
print("string.utf16.count: \(string.utf16.count)")
print("string.utf8.count: \(string.utf8.count)")
let nsstring: NSString = "👩‍👩‍👦‍👦"
print("nsstring length: \(nsstring.length)")
print("nsstring data length: \(String(describing: nsstring.data(using: String.Encoding.utf8.rawValue)?.count))")


// UnicodeScalar: 21位Unicode码元值
var str = String(UnicodeScalar(99))
var ch = Character(UnicodeScalar(UInt8(100)))

str.append(ch)

str.unicodeScalars.first?.value == 99
ch.unicodeScalars.first


var swift = "Swift is fun"
swift.dropFirst(9)

let group = "👩‍👩‍👦‍👦"
group.dropFirst(1)

let cafeeStr = "caf\u{0065}\u{0301}"
cafeeStr.dropFirst(4)
cafeeStr.dropLast()

cafeeStr.unicodeScalars.forEach { print($0) }
cafeeStr.utf8.forEach { print($0) }
cafeeStr.utf16.forEach { print($0) }

cafeeStr.unicodeScalars.dropLast()
cafeeStr.utf8.dropLast()
cafeeStr.utf16.dropLast()

//cafeeStr.characters
//cafeeStr.characters.count

//// String.Character.Index
//cafeeStr.characters.startIndex
//cafeeStr.characters.endIndex
//// cafeeStr.characters[2] 错误用法

// 1. Get character index
// O(n)
//let idx = cafeeStr.index(cafeeStr.startIndex, offsetBy: 3)
let idx = cafeeStr.index(cafeeStr.startIndex, offsetBy: 3, limitedBy: cafeeStr.endIndex)
// 2. Subscript access
cafeeStr[idx!]


extension String {
    subscript(index: Int) -> Character {
        guard let index = self.index(startIndex, offsetBy: index, limitedBy: endIndex) else {
            fatalError("String index out of range")
        }
        
        return self[index]
    }
}

cafeeStr[3]

for i in 0..<4 {
    print(cafeeStr[i])  // 0(n^2)
}





// canonical equivalence
// 这两种形式并不是等价的，因为包含不同的code point，却是canonically equivalent:即它们有相同的形态（按道理是看起来应该是一样的，但实际是不是一样就得问上帝了）和意思。
let eAcute: Character = "\u{E9}"                         // é
// é U00e9 "LATIN SMALL LETTER E WITH ACUTE"
let combinedEAcute: Character = "\u{65}\u{301}"          // e 后面加上 ‘
// e U0065 "LATIN SMALL LETTER E"
// ‘ U0301 "COMBINING ACUTE ACCENT"
eAcute.unicodeScalars.count
combinedEAcute.unicodeScalars.count
let sOne = String(eAcute)
let sTwo = String(combinedEAcute)
sOne.count
sTwo.count
sOne.utf8.count
sTwo.utf8.count
sOne.utf16.count
sTwo.utf16.count
sOne == sTwo
sOne.isEqual(sTwo)
sOne.decomposedStringWithCanonicalMapping.isEqual(sTwo.decomposedStringWithCanonicalMapping)

let nsOne = NSString(string: sOne)
let nsTwo = NSString(string: sTwo)
nsOne == nsTwo
nsOne.isEqual(to: nsTwo as String)
nsOne.decomposedStringWithCanonicalMapping.isEqual(nsTwo.decomposedStringWithCanonicalMapping)
let result = nsOne.compare(nsTwo as String)
result == .orderedSame


let circleSOne = sOne + "\u{20dd}"
circleSOne.count

"👩‍🦰".count
"👩‍👩‍👦‍👦".count

"👩\u{200d}👩\u{200d}👦\u{200d}👦" == "👩‍👩‍👦‍👦"



// compatibility equivalence
// 很多字符和序列则在广义上是重复的，在Unicode标准中称为 compatibility equivalence ，兼容序列代表相同的抽象字符，但可能没有相同的视觉体现或者行为。比如很多希腊字母，同时也用于数学了技术符号。罗马数字在标准拉丁字母之外额外编码在U+2160到 U+2183间。其它的兼容相等的例子是 ligatures：字符ﬀ (LATIN SMALL LIGATURE FF, U+FB00) 与序列 ff (LATIN SMALL LETTER F + LATIN SMALL LETTER F, U+0066 U+0066)兼容，但不是canonically equivalent，虽然它们可能渲染得完全一样，但取决于不同的上下文，typeface及文本渲染系统的能力。
let strOne = "\u{FB00}"
let strTwo = "\u{0066}\u{0066}"
strOne.isEqual(strTwo)
strOne.decomposedStringWithCompatibilityMapping.isEqual(strTwo.decomposedStringWithCompatibilityMapping)



// 常见的 String 字符串操作
let cafee = "caf\u{0065}\u{0301}"

let beg = cafee.startIndex
let end = cafee.index(beg, offsetBy: 3)
cafee[beg ..< end]

// 不能写成 cafee[0 ..< 3]
//String(cafee.characters.prefix(3))
String(cafee.prefix(3))

var mixStr = "Swift很有趣"
//for (index, value) in mixStr.characters.enumerated() {
for (index, value) in mixStr.enumerated() {
    print("\(index) \(value)")
}

if let index = mixStr.firstIndex(of: "很") {
    mixStr.insert(contentsOf: " 3.0", at: index)
}

if let cnIndex = mixStr.firstIndex(of: "很") {
    mixStr.replaceSubrange(cnIndex ..< mixStr.endIndex, with: " is interesting!")
}

String(mixStr.suffix(12).dropLast())

mixStr.split(separator: " ").map(String.init)

var i = 0

mixStr.split { _ in
    if i > 0 {
        i = 0
        return true
    } else {
        i += 1
        return false
    }
}.map(String.init)





