//
//  dispatch_cancel.h
//  Tools
//
//  Created by Simeon on 14/02/2015.
//  Copyright (c) 2015 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef BOOL (^dispatch_cancel_block_t)(BOOL cancelBlock);

dispatch_cancel_block_t dispatch_async_with_cancel_block(dispatch_queue_t queue, void (^block)());

#ifdef __cplusplus
}
#endif