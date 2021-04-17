//
//  NDTrie+Completion.h
//  Tools
//
//  Created by Simeon on 4/01/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import "NDTrie.h"

typedef id(^NDMutableTrieSetObjectBlock)(id obj, id existingObj, NSString *key, NSString *indexer);

@interface NDMutableTrie (Completion)

- (void) addCompletionList:(NSArray *)list;
- (void) addCompletionList:(NSArray *)list indexer:(NSString *)indexer;
- (void) addCompletionList:(NSArray *)list indexer:(NSString *)indexer setObjBlock:(NDMutableTrieSetObjectBlock)action;

@end
