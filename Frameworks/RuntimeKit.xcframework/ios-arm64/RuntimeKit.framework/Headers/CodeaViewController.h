//
//  CodeaViewController.h
//  Runtime
//
//  Created by Simeon on 11/11/12.
//  Copyright (c) 2012 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum CodeaViewMode
{
    CodeaViewModeStandard,
    CodeaViewModeOverlay,
    CodeaViewModeFullscreen,
    CodeaViewModeFullscreenNoButtons,
} CodeaViewMode;

@class CodeaSidebarViewController;
@class ThreadedRuntimeViewController;
@class Project;

@protocol CodeaAddon;

@interface CodeaViewController : UIViewController

@property (nonatomic, readonly, nonnull) ThreadedRuntimeViewController *runtime;
@property (nonatomic, readonly, nonnull) CodeaSidebarViewController *sidebar;

@property (nonatomic, assign) CodeaViewMode viewMode;
@property (nonatomic, assign) BOOL paused;
@property (nonatomic, assign) BOOL blankOverlay;
@property (nonatomic, assign) BOOL allowsFullscreenEscape;

- (nonnull instancetype) init;

- (nonnull instancetype) initWithRuntime:(nonnull ThreadedRuntimeViewController *)runtime;

- (void) setViewMode:(CodeaViewMode)viewMode animated:(BOOL)animated;

- (void) loadProjectAtPath:(nonnull NSString*)path;

- (void) loadProject:(nonnull Project*)project;

- (void) runProjectAtPath:(nonnull NSString *)path completion:(void(^)())completion;

- (void) registerAddon:(nonnull id<CodeaAddon>)addon;

- (void) setBlankOverlay:(BOOL)overlay animated:(BOOL)animated;

- (void) closeViewer;

@end
