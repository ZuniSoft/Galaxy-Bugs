//
//  assets.h
//  Runtime
//
//  Created by Simeon Saint-Saens on 21/1/20.
//  Copyright © 2020 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef Codea_assets_h
#define Codea_assets_h

#ifdef __cplusplus
extern "C" {
#endif
    #include "lua.h"
    
    NS_ASSUME_NONNULL_BEGIN

    typedef NS_OPTIONS(NSUInteger, AssetKeyStackOptions) {
        AssetKeyStackOptionsMustExist = 1 << 1,
        AssetKeyStackOptionsAllowLibraries = 1 << 2,
        AssetKeyStackOptionsShowWarning = 1 << 3,
    };

    void luamodule_assets(lua_State *L, BOOL isRunningInCodea);
    
    //MARK: Asset paths

    NSString* _Nullable assetKeyOnStackAtIndex(struct lua_State *L, int idx);
    NSString* _Nullable assetPathOnStackAtIndex(struct lua_State *L, int idx, AssetKeyStackOptions options);

    NSArray<NSDictionary<NSString*, NSString*> *> *assetLocations(NSString *projectPath, BOOL isHosted);

    NSString* _Nullable assetCodePath(NSString *path, NSString* _Nullable projectPath);

    NS_ASSUME_NONNULL_END
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

struct AssetKey {

    std::string _path;
    
    AssetKey() {}
    
    AssetKey(const std::string& path): _path(path) {}
    
    void configure(const std::string& path) {
        _path = path;
    }
    
    std::string name() const {
        NSString *nsPath = [NSString stringWithUTF8String:_path.c_str()];
        return nsPath.lastPathComponent.UTF8String;
    }
            
    const std::string& path() const {
        return _path;
    }
    
    std::string ext() const;
    
    std::string type() const;
    
    static AssetKey empty() {
        return AssetKey("");
    }
    
    bool isEmpty() const {
        return _path == "";
    }
};

inline bool operator==(const AssetKey& lhs, const AssetKey& rhs) {
    return lhs._path == rhs._path;
}

std::string assetLibraryPath(lua_State* _Nonnull L, int index);

#endif

#endif
