//
//  NSArray+Reverse.h
//  Tools
//
//  Created by Simeon on 22/01/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Reverse)

- (NSArray *)reversedArray;

@end

@interface NSMutableArray (Reverse)

- (void)reverse;

@end