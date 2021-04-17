//
//  NSString+ShortForm.h
//  Cloud Clinic
//
//  Created by Simeon on 2/04/13.
//  Copyright (c) 2013 Enabled. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (ShortForm)

- (NSString*) asciiVersion;
- (NSString*) asciiAlphanumericOnlyVersion;

- (NSString*) urlHostOnlyVersion;

@end
