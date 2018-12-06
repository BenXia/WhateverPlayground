//
//  BOOLTestVC.m
//  TestTemplateProject
//
//  Created by Ben on 2017/9/3.
//  Copyright © 2017年 iOSStudio. All rights reserved.
//

#import "BOOLTestVC.h"

//Update October 2013 - On 64-bit iOS (device and simulator) BOOL is now actually bool, so the sharp corners have thankfully gone away for that platform.

static BOOL different (int thing1, int thing2) {
    return thing1 - thing2;
} // difference

static NSString *g_name2 = @"wjkflasj";
static NSString *g_name = @"wjkflasjdf";

static __unsafe_unretained BOOLTestVC* gTimer;

static BOOL haveName () {
    return (BOOL)g_name;  //(BOOL)0x10000000;
} // haveName

//static BOOL haveName () {
//    if (g_name) {
//        return YES;
//    } else {
//        return NO;
//    }
//} // haveName
//
//static BOOL haveName () {
//    return g_name != nil;
//} // haveName

@interface BOOLTestVC ()

@property (nonatomic, strong) NSTimer *timer;

@end

@implementation BOOLTestVC

#pragma mark - View life cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.timer = [NSTimer scheduledTimerWithTimeInterval:3 repeats:YES block:^(NSTimer * _Nonnull timer) {
        NSLog(@"Hello world");
    }];
    NSLog (@"self.timer: %@ class: %@", self.timer, [self.timer class]);
    
//
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        NSLog (@"invalid timer");
//        [self.timer invalidate];
//        self.timer = nil;
//    });
//
    gTimer = self;
    
    
//    [self testCaseOne];
//    
//    [self testCaseTwo];
//    
//    [self testCaseThree];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - TestCases

- (void)testCaseOne {
    if (different(11, 10) == YES) printf ("11 != 10\n");
    else printf ("11 == 10\n");
    
    if (different(10, 11) == YES) printf ("10 != 11\n");
    else printf ("10 == 11\n");
    
    if (different(10, 15) == YES) printf ("10 != 15\n");
    else printf ("10 == 15\n");
    
    if (different(512, 256) == YES) printf ("512 != 256\n");
    else printf ("512 == 256\n");
}

- (void)testCaseTwo {
    BOOL truefalse = (BOOL)256;
    printf ("256 -> %d\n", truefalse);
    
    bool stdTruefalse = (bool)256;
    printf ("256 -> %d (bool)\n", stdTruefalse);
}

- (void)testCaseThree {
    printf ("haveName -> %d \n", haveName());
}

- (void)dealloc {
    NSLog (@"gTimer: %@", gTimer);
    NSLog (@"self: %@", self);
    if ([self isKindOfClass:[BOOLTestVC class]] && (gTimer == self)) {
        NSLog (@"BOOLTestVC dealloc");
    }
}

@end


static NSMutableArray *g_array;

@implementation NSObject (DEALLOC_LOG)

+ (void)load {
    g_array = [NSMutableArray array];
}

- (void)dealloc {
    [g_array addObject:[self class]];
    
    if (gTimer == self) {
        //    if ([self isKindOfClass:[BOOLTestVC class]]) {
        NSLog (@">NSObject dealloc");
    }
}

@end


////static NSMutableArray *g_array;
//
//@implementation BOOLTestVC (DEALLOC_LOG)
//
////+ (void)load {
////    g_array = [NSMutableArray array];
////}
//
//- (void)dealloc {
////    [g_array addObject:[self class]];
//
////    static int a = 1;
////
////    if ((a == 1) && ([self isKindOfClass:[BOOLTestVC class]] || gTimer)) {
////        a = 2;
////        NSLog (@"self: %@ gTimer: %@", self, gTimer);
////    }
//
//    if (gTimer == self) {
////    if ([self isKindOfClass:[BOOLTestVC class]]) {
//        NSLog (@">BOOLTestVC dealloc");
//    }
//}
//
//@end





