//
//  ThreadedRuntimeViewController.h
//  Runtime
//
//  Created by Dylan Sale on 28/01/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "CodeaViewController.h"
#import "CodeaLuaState.h"
#import "EAGLView.h"

@class Project;
@class CodeaScriptExecute;
@class ScreenCapture;
@class RenderManager;
@class PhysicsManager;
@class ShaderManager;
@class TextureCache;
@class KeyboardInputView;
@class AFHTTPRequestOperationManager;
@class LocationManager;

@class ThreadedRuntimeViewController;

@protocol ScriptValidateErrorDelegate;
@protocol CodeaLuaStateDelegate;
@protocol ScreenCaptureDelegate;

@protocol ThreadedRuntimeViewControllerDelegate <NSObject>

@optional
    //Asynchronous
    - (void)runtimeViewController:(id)context willPause:(BOOL)pause;
    - (void)runtimeViewControllerWillRestart:(id)context;
    - (void)runtimeViewControllerDidRestart:(id)context;
    - (void)runtimeViewControllerUpdate:(id)context;
    - (void)runtimeViewControllerWillClose:(id)context;
    - (void)runtimeViewController:(id)context changeBackingMode:(BOOL)retained;
    - (void)runtimeViewControllerDidFinishSetup:(id)context;

    //Synchronous
    - (void)runtimeViewControllerWillDraw:(id)context;
    - (void)runtimeViewControllerDidDraw:(id)context;

    - (CGRect)runtimeViewController:(id)context didChangeViewMode:(CodeaViewMode)mode animated:(BOOL)animated;
    - (BOOL)runtimeViewControllerHasRetainedBacking:(id)context;
@end

@interface ThreadedRuntimeViewController : UIViewController

@property (weak, nonatomic) id<ThreadedRuntimeViewControllerDelegate> delegate;
@property (assign, nonatomic) CodeaViewMode viewMode;
/**
 Warning, the lua and screen capture delegate methods occur on the lua thread. This is a leaky abstraction, but c'est la vie.
 
 (•_•)
 ( •_•)>⌐■-■
 (⌐■_■)
 
 Deal With It.
*/
@property (weak, nonatomic) id<CodeaLuaStateDelegate> luaDelegate;
@property (weak, nonatomic) id<ScreenCaptureDelegate> screenCaptureDelegate;

@property (strong, nonatomic) Project *project;

- (void) setErrorDelegate:(id<ScriptValidateErrorDelegate>)errorDelegate;

- (void) evaluateString:(NSString*) string;

- (void) loadString:(NSString*) string completion:(void(^)(LuaError))completion;

- (void) hasScriptGlobal:(NSString *)name completion:(void(^)(BOOL))completion;

- (void) canChangeDisplayMode:(void(^)(BOOL))block;

- (void) validateProject:(Project*)project completionBlock:(void(^)(BOOL))block; //Runs completion block on the main thread, validates the project on the lua thread

#pragma mark - Unsafe stuff that you should only touch if you know what you are doing.

#pragma mark - Threading

//This leaks the luaState abstraction by passing it into a block.
//It should be removed but its the best solution for some legacy stuff for now.
//It will run the block on the lua thread.
#pragma warning This causes an unsafe abstraction leak.
- (void) unsafeRunLuaBlock:(void(^)(CodeaLuaState* state))block;

- (void) runBlock:(dispatch_block_t)block;
- (void) runBlockSync:(dispatch_block_t)block;
- (void) runGLBlock:(dispatch_block_t)block;
- (void) runGLBlockSync:(dispatch_block_t)block;

#pragma mark - Animation

- (void)startAnimation;
- (void)stopAnimationAndForceCancelFrame:(BOOL)forceFrame;

#pragma mark - EAGL

- (EAGLView*) glView;

#pragma mark - Frame timing

- (NSTimeInterval) currentDelta;

#pragma mark - Screen recording

- (void) stopRecording:(dispatch_block_t)completionBlock;
- (void) stopRecordingAndDiscard:(void(^)(BOOL stopped))completionBlock;
- (void) discardMovie;
- (void) saveMovieToCameraRoll;
- (void) toggleRecording;

- (void) screenshot:(void(^)(UIImage* capture))capture;
- (void) screenshotAtScaleFactor:(CGFloat)scaleFactor completion:(void(^)(UIImage* capture))capture;

@property (nonatomic, assign) BOOL paused;

- (void) start:(void(^)())completion;
- (void) restart;
- (void) close;

@end
