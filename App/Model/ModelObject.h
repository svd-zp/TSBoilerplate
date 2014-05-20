/*
 Copyright 2011 Marko Karppinen & Co. LLC.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 ModelObject.h
 mogenerator / PONSO
 Created by Nikita Zhuk on 22.1.2011.
 */

/**
	Abstract superclass for all of our model classes.
 */

@protocol ObjectCollection <NSObject>

@end

@protocol CacheableModelObject <NSObject>

@required
-(void)clearCache;

@end

#import <Foundation/Foundation.h>

@interface ModelObject : NSObject <NSCopying, NSSecureCoding>
{
	NSDictionary *sourceDictionaryRepresentation;
}

@property(nonatomic, retain) NSDictionary *sourceDictionaryRepresentation;
@property(nonatomic, readonly, assign, getter=isPopulated) BOOL populated;

+ (id)modelObjectWithClass:(Class)aClass FromObject:(ModelObject *)object;
+ (id)modelObjectFromObject:(ModelObject *)object;

- (id)initWithDictionaryRepresentation:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryRepresentation;

+ (NSSet *)dictionaryRepresentationKeys;

- (void)awakeFromDictionaryRepresentationInit;
+ (BOOL)supportsSecureCoding;
@end


@interface NSMutableDictionary (PONSONSMutableDictionaryAdditions)

- (void)setObjectIfNotNil:(id)obj forKey:(NSString *)key;

@end
