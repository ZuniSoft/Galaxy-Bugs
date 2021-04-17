//
//  StandaloneCodeaViewController.h
//  Runtime
//
//  Created by Simeon on 15/10/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "CodeaViewController.h"

@protocol CodeaAddon;

@interface StandaloneCodeaViewController : UIViewController

@property (nonatomic, assign) CodeaViewMode viewMode;
@property (nonatomic, assign) BOOL paused;

- (instancetype) initWithProjectAtPath:(NSString *)path;

- (void) setViewMode:(CodeaViewMode)viewMode animated:(BOOL)animated;

- (void) registerAddon:(id<CodeaAddon>)addon;

@end
