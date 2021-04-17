//
//  Renderer.h
//  LimbicGL
//
//  Created by Volker Schönefeld on 6/12/11.
//  Copyright 2011 Limbic Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#if !TARGET_OS_MACCATALYST
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <OpenGLES/ES3/gl.h>
#import <OpenGLES/ES3/glext.h>
#endif

#import "Driver.h"

@class CAEAGLLayer;
@class RenderTarget;
@class Renderer;

@protocol Game;

@protocol RendererDelegate <NSObject>

- (void) renderer:(Renderer*)renderer willPause:(BOOL)pause;

@end

@interface Renderer : NSObject {
@private
    id<Game> game_;
    RenderTarget *rendertarget;
    id<Driver> driver_;
}

@property (nonatomic, weak) id<Game> game;
@property (nonatomic, weak) id<RendererDelegate> delegate;
@property (nonatomic, readonly) id<Driver> driver;

// Called whenever the underlying UIView is re-layouted
#if !TARGET_OS_MACCATALYST
- (void)setLayer:(CAEAGLLayer *)layer;
#endif
// start animating the scene at 60hz
- (void)startAnimation;
// stop the animation
- (void)stopAnimation;

- (BOOL)isAnimating;

- (UIImage*) screenshot:(CGFloat)contentScaleFactor;

- (void) runBlock:(dispatch_block_t)block;
- (void) runGLBlock:(dispatch_block_t)block;
- (void) runBlockSync:(dispatch_block_t)block;
- (void) runGLBlockSync:(dispatch_block_t)block;

#pragma mark - GL Related

- (void) bindDrawable;
- (void) setViewport;

#if !TARGET_OS_MACCATALYST
- (EAGLContext*) eaglContext;
#endif

@end
