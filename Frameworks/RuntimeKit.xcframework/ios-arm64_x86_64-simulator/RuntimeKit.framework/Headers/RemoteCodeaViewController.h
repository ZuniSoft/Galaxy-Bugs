//
//  RemoteCodeaViewController.h
//  Runtime
//
//  Created by Simeon on 5/06/13.
//  Copyright (c) 2013 Two Lives Left. All rights reserved.
//

@class Project;

@interface RemoteCodeaViewController : CodeaViewController

- (void) validateScript:(NSString*)script completion:(void(^)(BOOL))completion;

@end
