//
//  ProjectManager+Load.h
//  RuntimeKit
//
//  Created by Simeon Saint-Saens on 26/11/18.
//  Copyright © 2018 Two Lives Left. All rights reserved.
//

#import "ProjectManager.h"

@class Project;

NS_ASSUME_NONNULL_BEGIN

@interface ProjectManager (Load)

+ (NSArray<Project*>*) loadProjectsInList:(NSArray*)list inPath:(NSString*)path userProjects:(BOOL)user;

+ (NSArray<Project*>*) loadProjectsInPath:(NSString*)path userProjects:(BOOL)user comparator:(NSComparator)comparator;

+ (NSArray<Project*>*) loadProjectsInPath:(NSString*)path userProjects:(BOOL)user;

@end

NS_ASSUME_NONNULL_END
