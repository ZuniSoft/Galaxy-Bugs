//
//  ProjectManager+Create.h
//  Runtime
//
//  Created by Simeon Saint-Saens on 26/11/18.
//  Copyright © 2018 Two Lives Left. All rights reserved.
//

#import "ProjectManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ProjectManager (Create)

+ (Project*) createProject:(NSString*)name withTemplate:(Project*)templateProject inCollection:(ProjectCollection *)collection;
+ (Project*) createProject:(NSString*)name withProjectString:(NSString *)projectString inCollection:(ProjectCollection *)collection;

@end

NS_ASSUME_NONNULL_END
