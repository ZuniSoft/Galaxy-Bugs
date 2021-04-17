//
//  UIViewController+TraitHelpers.h
//  Codea
//
//  Created by Simeon on 16/12/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (TraitHelpers)

@property (nonatomic, readonly) BOOL shouldUseCompactLayout;

- (UIUserInterfaceSizeClass) horizontalSizeClass;
- (UIUserInterfaceSizeClass) verticalSizeClass;
- (UIUserInterfaceIdiom) userInterfaceIdiom;

- (BOOL) containsAnyTraitsInCollections:(NSArray *)collections;

@end
