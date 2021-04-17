//
//  ProjectManager.h
//  Codea
//
//  Created by Simeon Saint-Saëns on 17/09/11.
//  Copyright 2011 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* const kProjectManagerDidCopyExamplesNotification;
extern NSString* const kDefaultProjectCollectionName;

typedef NS_ENUM(NSInteger, ProjectCollectionSorting);

@class Project;
@class ProjectManager;
@class ProjectCollection;
@class LocalProjectRepository;

@interface ProjectManager : NSObject

@property (nonatomic, readonly) NSArray<Project*> *templateProjects;
@property (nonatomic, readonly) Project *defaultProjectTemplate;

@property (nonatomic, readonly) LocalProjectRepository *local;

@property (nonatomic, assign) ProjectCollectionSorting sortOrder;

+ (instancetype) shared;

- (nullable Project*) projectNamed:(NSString*)name;

- (nullable ProjectCollection*) collectionNamed:(NSString*)name;

- (nullable ProjectCollection*) collectionForProject:(Project*)project;

- (BOOL) hasProjectNamed:(NSString*)name;

- (BOOL) saveProject:(Project*)project;

- (void) embedDependenciesIntoProject:(Project*)project;

+ (BOOL) isProjectStringValid:(NSString*)projectString;

@end

NS_ASSUME_NONNULL_END
