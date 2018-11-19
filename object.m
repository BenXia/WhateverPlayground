#import <Foundation/Foundation.h>

@interface Model : NSObject <NSCopying>

@property (nonatomic, assign) int age;
@property (nonatomic, copy) NSString *name;

- (void)printDetail;

@end

@implementation Model

- (void)printDetail {
    NSLog (@"detail age: %d name: %@", _age, _name);
}

- (id)copyWithZone:(NSZone *)zone {
    Model *copy = [[Model alloc] init];
    copy.age = self.age;
    copy.name = self.name;
    return copy;
}

@end
