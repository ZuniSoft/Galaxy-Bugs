//
//  LuaRefContainer.h
//  RuntimeKit
//
//  Created by Simeon Saint-Saens on 4/10/18.
//  Copyright © 2018 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
namespace LuaIntf {
    class LuaRef;
}
#endif

NS_ASSUME_NONNULL_BEGIN

@interface LuaRefContainer : NSObject

#ifdef __cplusplus
@property (nonatomic, readonly) LuaIntf::LuaRef reference;

- (nonnull instancetype) initWithReference:(LuaIntf::LuaRef)ref;
#endif

- (void) unreference;

@end

NS_ASSUME_NONNULL_END
