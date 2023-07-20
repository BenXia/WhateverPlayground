//
//  TsetSDocument.swift
//  TsetS
//
//  Created by Ben on 2023/4/29.
//

import SwiftUI
import UniformTypeIdentifiers

extension UTType {
    static var exampleText: UTType {
        UTType(importedAs: "com.example.plain-text")
    }
}

//class Solution {
//    func dfsRecursive(_ n: Int, _ parent: Int, _ manager: inout [Int], _ informTime: inout [Int], _ currentInformTime: Int, _ maxTime: inout Int) {
//        if currentInformTime + informTime[parent] > maxTime {
//            maxTime = currentInformTime + informTime[parent]
//        }
//
//        for i in 0..<n {
//            if manager[i] == parent {
//                dfsRecursive(n, i, &manager, &informTime, currentInformTime + informTime[parent], &maxTime)
//            }
//        }
//    }
//
//    func numOfMinutes(_ n: Int, _ headID: Int, _ manager: [Int], _ informTime: [Int]) -> Int {
//        var maxTime = 0
//        var managerCopy = manager
//        var informTimeCopy = informTime
//
//        dfsRecursive(n, headID, &managerCopy, &informTimeCopy, informTime[headID], &maxTime)
//
//        return maxTime
//    }
//}

class DinnerPlates {

    private var stackArray = [[Int]]()
    private var notFullStackIndexArray = [Int]()
    private var stackSize = 0
    private var capacity = 0

    init(_ capacity: Int) {
        self.capacity = capacity
    }
    
    func push(_ val: Int) {
        if self.stackSize == 0 {
            var newPage = [Int](repeating:-1, count:self.capacity)
            newPage[0] = val
            self.stackArray.append(newPage)
            self.stackSize += 1

            if 1 < self.capacity {
                self.notFullStackIndexArray.append(0)
            }
        } else {
            if self.notFullStackIndexArray.count != 0 {
                var firstNotFullStackIndex = self.notFullStackIndexArray[0]

                var resultIndex = -1
                for j in 0..<self.capacity {
                    if self.stackArray[firstNotFullStackIndex][j] == -1 {
                        resultIndex = j
                        self.stackArray[firstNotFullStackIndex][j] = val
                        break
                    }
                }

                if resultIndex == self.capacity - 1 {
                    self.notFullStackIndexArray.remove(at:0)
                }
            } else {
                var newPage = [Int](repeating:-1, count:self.capacity)
                newPage[0] = val
                self.stackArray.append(newPage)
                self.stackSize += 1

                if 1 < self.capacity {
                    self.notFullStackIndexArray.append(self.stackArray.count - 1)
                }
            }
        }
    }
    
    func pop() -> Int {
        if self.stackSize == 0 {
            return -1
        } else {
            var currentStackSize = self.stackSize
            for i in 0..<currentStackSize {
                if self.stackArray[currentStackSize - 1 - i][0] != -1 {
                    var result = -1, resultIndex = -1
                    for j in 0..<self.capacity {
                        if self.stackArray[currentStackSize - 1 - i][j] == -1 {
                            break;
                        } else {
                            result = self.stackArray[currentStackSize - 1 - i][j]
                            resultIndex = j
                        }
                    }

                    if resultIndex == 0 {
                        self.stackArray.remove(at:currentStackSize - 1 - i)

                        if self.notFullStackIndexArray.count > 0 && self.notFullStackIndexArray[self.notFullStackIndexArray.count - 1] == currentStackSize - 1 - i {
                            self.notFullStackIndexArray.remove(at:self.notFullStackIndexArray.count - 1)
                        }
                    } else {
                        self.stackArray[currentStackSize - 1 - i][resultIndex] = -1
                        
                        if self.notFullStackIndexArray.count == 0 || self.notFullStackIndexArray[self.notFullStackIndexArray.count - 1] != currentStackSize - 1 - i {
                                                    self.notFullStackIndexArray.append(currentStackSize - 1 - i)
                                                }
                    }

                    self.stackSize = self.stackArray.count

                    return result
                } else {
                    self.stackArray.remove(at:currentStackSize - 1 - i)

                    if self.notFullStackIndexArray.count > 0 && self.notFullStackIndexArray[self.notFullStackIndexArray.count - 1] == currentStackSize - 1 - i {
                        self.notFullStackIndexArray.remove(at:self.notFullStackIndexArray.count - 1)
                    }
                }
            }

            self.stackSize = self.stackArray.count

            return -1
        }
    }
    
    func popAtStack(_ index: Int) -> Int {
        if self.stackSize > index {
            var result = -1, resultIndex = -1
            if self.stackArray[index][0] != -1 {
                for i in 0..<self.capacity {
                    if self.stackArray[index][i] == -1 {
                        break;
                    } else {
                        resultIndex = i
                        result = self.stackArray[index][i]
                    }
                }
            }

            if resultIndex == -1 {
                // self.stackArray.remove(at:index)
                // self.stackSize -= 1
            } else {
                self.stackArray[index][resultIndex] = -1

                if resultIndex == 0 && index == self.stackArray.count - 1 {
                    self.stackArray.remove(at:self.stackArray.count - 1)
                    self.stackSize -= 1
                    if self.notFullStackIndexArray.count > 0 && self.notFullStackIndexArray[self.notFullStackIndexArray.count - 1] == index {
                        self.notFullStackIndexArray.remove(at:self.notFullStackIndexArray.count - 1)
                    }

                    return result
                }
            }

            var left = 0, right = self.notFullStackIndexArray.count - 1, mid = 0, lastRight = self.notFullStackIndexArray.count

            while left <= right {
                mid = (left + right) / 2

                if self.notFullStackIndexArray[mid] >= index {
                    lastRight = mid
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            }

            if lastRight == self.notFullStackIndexArray.count {
                self.notFullStackIndexArray.append(index)
            } else if self.notFullStackIndexArray[lastRight] != index {
                self.notFullStackIndexArray.append(index)
                if lastRight <= self.notFullStackIndexArray.count - 2 {
                    var tmp = self.notFullStackIndexArray.count + lastRight
                    var end = self.notFullStackIndexArray.count - 1
                    // var count = self.notFullStackIndexArray.count - 2 - lastRight + 1

                    // for i in 0..<count {
                    //     self.notFullStackIndexArray[self.notFullStackIndexArray.count - 1 - i] = self.notFullStackIndexArray[self.notFullStackIndexArray.count - 2 - i]
                    // }

                    for i in lastRight..<end {
                        self.notFullStackIndexArray[tmp - i - 1] = self.notFullStackIndexArray[tmp - i - 2]
                    }
                }

                self.notFullStackIndexArray[lastRight] = index
            }

            return result
        } else {
            return -1
        }
    }
}

//class Solution {
//    func maxTotalFruits(_ fruits: [[Int]], _ startPos: Int, _ k: Int) -> Int {
//        if fruits.count == 0 {
//            return 0
//        }
//        if k == 0 {
//            for i in 0..<fruits.count {
//                if fruits[i][0] == startPos {
//                    return fruits[i][1]
//                }
//            }
//
//            return 0
//        }
//
//        var minStart = startPos - k, maxStart = startPos, minEnd = startPos, maxEnd = startPos + k
//        var endPosCount = [UInt](repeating:0, count:2 * k + 1)
//        var endPrefixSum = [UInt](repeating:0, count:2 * k + 1)
//        for i in 0..<fruits.count {
//            if fruits[i][0] >= minStart && fruits[i][0] <= minStart + 2 * k {
//                endPosCount[fruits[i][0] - minStart] = UInt(fruits[i][1])
//            }
//        }
//        endPrefixSum[0] = endPosCount[0]
//        for i in 1...2*k {
//            endPrefixSum[i] = endPosCount[i] + endPrefixSum[i-1]
//        }
//
//        var maxCount: UInt = 0
//        var endIndex = 0
//        for i in 0...k {
//            endIndex = k - (k - i) * 2 + k
//            if endIndex < k {
//                endIndex = k
//            }
//
//            if i == 0 {
//                if endPrefixSum[endIndex] > maxCount {
//                    maxCount = endPrefixSum[endIndex]
//                }
//            } else {
//                if endPrefixSum[endIndex] - endPrefixSum[i-1] > maxCount {
//                    maxCount = endPrefixSum[endIndex] - endPrefixSum[i-1]
//                }
//            }
//        }
//
//        return Int(maxCount)
//    }
//}


class Solution {
    func maxValueAfterReverse(_ nums: [Int]) -> Int {
        if nums.count < 2 {
            return 0
        } else if nums.count == 2 {
            return Swift.abs(nums[0] - nums[1])
        }

        var sumAbs = 0, cMaxAbs = 0, maxAbs = 0, maxI = 0, maxJ = nums.count - 1, absV = 0, absX1 = 0, absY1 = 0, absX2 = 0, absY2 = 0
        var absArray = [Int]()
        //[63674,-34608,86424,-52056,-3992,93347,2084,-28546,-75702,-28400]
        //98282, 121032, 138480, 48064, 97339, 91263, 30630, 47156, 47302  = 719548
        
        //[2,4,9,24,2,1,10]
        //2,5,15,22,1,9
        
        for i in 0..<nums.count - 1 {
            absV = Swift.abs(nums[i] - nums[i+1])
            absArray.append(absV)
            maxAbs += absV
        }
        sumAbs = maxAbs

        for i in 0..<nums.count - 1 {
            if i == 0 {
                absX1 = 0
            } else {
                absX1 = absArray[i-1]
            }

            for j in i+1..<nums.count {
                if j == nums.count - 1 {
                    absY1 = 0
                } else {
                    absY1 = absArray[j]
                }
                if i > 0 {
                    absX2 = Swift.abs(nums[i-1] - nums[j])
                } else {
                    absX2 = 0
                }
                if j == nums.count - 1 {
                    absY2 = 0
                } else {
                    absY2 = Swift.abs(nums[j+1] - nums[i])
                }

                cMaxAbs = sumAbs + absX2 + absY2 - absX1 - absY1
                if cMaxAbs > maxAbs {
                    maxAbs = cMaxAbs
                    maxI = i
                    maxJ = j
                }
            }
        }

        return maxAbs
    }
}


struct TsetSDocument: FileDocument {
    var text: String

    init(text: String = "Hello, world!") {
        self.text = text
        
//        var solution = Solution()
//        solution.maxTotalFruits([[0,7],[7,4],[9,10],[12,6],[14,8],[16,5],[17,8],[19,4],[20,1],[21,3],[24,3],[25,3],[26,1],[28,10],[30,9],[31,6],[32,1],[37,5],[40,9]], 21, 30)
        
//        let obj = DinnerPlates(2)
//        obj.push(1)
//        obj.push(2)
//        obj.push(3)
//        obj.push(4)
//        obj.push(5)
//
//        print("\(obj.popAtStack(0))")
//
//        obj.push(20)
//        obj.push(21)
//
//        print("\(obj.popAtStack(0))")
//        print("\(obj.popAtStack(2))")
//
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
        
        
        
//        ["DinnerPlates","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","popAtStack","popAtStack","popAtStack","popAtStack","popAtStack","popAtStack","popAtStack","popAtStack","popAtStack","popAtStack","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","push","pop","pop","pop","pop","pop","pop","pop","pop","pop","pop"]
//
//
//        [[2],[373],[86],[395],[306],[370],[94],[41],[17],[387],[403],[66],[82],[27],[335],[252],[6],[269],[231],[35],[346],[4],[6],[2],[5],[2],[2],[7],[9],[8],[1],[474],[216],[256],[196],[332],[43],[75],[22],[273],[101],[11],[403],[33],[365],[338],[331],[134],[1],[250],[19],[],[],[],[],[],[],[],[],[],[]]
        
//        let obj = DinnerPlates(2)
//        obj.push(373)
//        obj.push(86)
//        obj.push(395)
//        obj.push(306)
//        obj.push(370)
//
//        obj.push(94)
//        obj.push(41)
//        obj.push(17)
//        obj.push(387)
//        obj.push(403)
//
//        obj.push(66)
//        obj.push(82)
//        obj.push(27)
//        obj.push(335)
//        obj.push(252)
//
//        obj.push(6)
//        obj.push(269)
//        obj.push(231)
//        obj.push(35)
//        obj.push(346)
//
//        print("\(obj.popAtStack(4))")
//        print("\(obj.popAtStack(6))")
//        print("\(obj.popAtStack(2))")
//        print("\(obj.popAtStack(5))")
//        print("\(obj.popAtStack(2))")
//        print("\(obj.popAtStack(2))")
//        print("\(obj.popAtStack(7))")
//        print("\(obj.popAtStack(9))")
//        print("\(obj.popAtStack(8))")
//        print("\(obj.popAtStack(1))")
//
//        obj.push(474)
//        obj.push(216)
//        obj.push(256)
//        obj.push(196)
//        obj.push(332)
//        obj.push(43)
//        obj.push(75)
//        obj.push(22)
//        obj.push(273)
//        obj.push(101)
//        obj.push(11)
//        obj.push(403)
//        obj.push(33)
//        obj.push(365)
//        obj.push(338)
//        obj.push(331)
//        obj.push(134)
//        obj.push(1)
//        obj.push(250)
//        obj.push(19)
//
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
//        print("\(obj.pop)")
        
        
        
//        let obj = DinnerPlates(2)
//        obj.push(1)
//        obj.push(2)
//        obj.push(3)
//        obj.push(4)
//
//        print("\(obj.pop())")
//
//        obj.push(4)
//
//        print("\(obj.popAtStack(1))")
        
        
        var solution = Solution()
//        solution.maxValueAfterReverse([63674,-34608,86424,-52056,-3992,93347,2084,-28546,-75702,-28400])
//        //98282, 121032, 138480, 48064, 97339, 91263, 30630, 47156, 47302  = 719548
        
        solution.maxValueAfterReverse([2,4,9,24,2,1,10])
        //2,5,15,22,1,9
    }

    static var readableContentTypes: [UTType] { [.exampleText] }

    init(configuration: ReadConfiguration) throws {
        guard let data = configuration.file.regularFileContents,
              let string = String(data: data, encoding: .utf8)
        else {
            throw CocoaError(.fileReadCorruptFile)
        }
        text = string
    }
    
    func fileWrapper(configuration: WriteConfiguration) throws -> FileWrapper {
        let data = text.data(using: .utf8)!
        return .init(regularFileWithContents: data)
    }
}
