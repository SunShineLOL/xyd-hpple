//
//  TFHppleElement.h
//  Hpple
//
//  Created by Geoffrey Grosenbach on 1/31/09.
//
//  Copyright (c) 2009 Topfunky Corporation, http://topfunky.com
//
//  MIT LICENSE
//
//  Permission is hereby granted, free of charge, to any person obtaining
//  a copy of this software and associated documentation files (the
//  "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish,
//  distribute, sublicense, and/or sell copies of the Software, and to
//  permit persons to whom the Software is furnished to do so, subject to
//  the following conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZNHppleElement : NSObject

- (id) initWithNode:(NSDictionary *) theNode isXML:(BOOL)isDataXML withEncoding:(nullable NSString *)theEncoding;

+ (ZNHppleElement *) hppleElementWithNode:(NSDictionary *) theNode isXML:(BOOL)isDataXML withEncoding:(nullable NSString *)theEncoding;

@property (nonatomic, copy, readonly) NSString *raw;
// Returns this tag's innerHTML content.
@property (nonatomic, copy, readonly, nullable) NSString *content;

// Returns the name of the current tag, such as "h3".
@property (nonatomic, copy, readonly, nullable) NSString *tagName;

// Returns tag attributes with name as key and content as value.
//   href  = 'http://peepcode.com'
//   class = 'highlight'
@property (nonatomic, strong, readonly) NSDictionary *attributes;

// Returns the children of a given node
@property (nonatomic, strong, readonly) NSArray *children;

// Returns the first child of a given node
@property (nonatomic, strong, readonly, nullable) ZNHppleElement *firstChild;

// the parent of a node
@property (nonatomic, unsafe_unretained, readonly) ZNHppleElement *parent;

// Returns YES if the node has any child
// This is more efficient than using the children property since no NSArray is constructed
- (BOOL)hasChildren;

// Returns YES if this is a text node
- (BOOL)isTextNode;

// Provides easy access to the content of a specific attribute, 
// such as 'href' or 'class'.
- (nullable NSString *) objectForKey:(NSString *) theKey;

// Returns the children whose tag name equals the given string
// (comparison is performed with NSString's isEqualToString)
// Returns an empty array if no matching child is found
- (NSArray<ZNHppleElement *> *) childrenWithTagName:(NSString *)tagName;

// Returns the first child node whose tag name equals the given string
// (comparison is performed with NSString's isEqualToString)
// Returns nil if no matching child is found
- (nullable ZNHppleElement *) firstChildWithTagName:(NSString *)tagName;

// Returns the children whose class equals the given string
// (comparison is performed with NSString's isEqualToString)
// Returns an empty array if no matching child is found
- (NSArray<ZNHppleElement *> *) childrenWithClassName:(NSString *)className;

// Returns the first child whose class requals the given string
// (comparison is performed with NSString's isEqualToString)
// Returns nil if no matching child is found
- (nullable ZNHppleElement *) firstChildWithClassName:(NSString*)className;

// Returns the first text node from this element's children
// Returns nil if there is no text node among the children
- (nullable ZNHppleElement *) firstTextChild;

// Returns the string contained by the first text node from this element's children
// Convenience method which can be used instead of firstTextChild.content
- (nullable NSString *) text;

// Returns elements searched with xpath
- (NSArray<ZNHppleElement *> *) searchWithXPathQuery:(NSString *)xPathOrCSS;

// Custom keyed subscripting
- (nullable id)objectForKeyedSubscript:(id)key;


@end

NS_ASSUME_NONNULL_END
