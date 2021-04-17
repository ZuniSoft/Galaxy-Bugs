//
//  ProjectAssetPack.h
//  Codea
//
//  Created by Simeon on 28/08/2014.
//  Copyright (c) 2014 Developer. All rights reserved.
//

#import "AssetPack.h"

@class Project;

@interface ProjectAssetPack : AssetPack

@property (nonatomic, readonly) NSString *projectName;

- (id) initWithProject:(Project *)project;

@end
