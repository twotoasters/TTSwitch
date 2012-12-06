//
//  TTControlTableItem.h
//  TTSwitch
//
//  Created by Scott Penrose on 12/5/12.
//  Copyright (c) 2012 Two Toasters. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TTControlItem : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) UIControl *control;

+ (id)itemWithTitle:(NSString *)title control:(UIControl *)control;

@end
