//
//  NSArray+Map.h
//  Tools
//
//  Created by Simeon on 21/01/2015.
//  Copyright (c) 2015 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Map)

- (NSArray *)mapObjectsUsingBlock:(id (^)(id obj, NSUInteger idx))block;

@end