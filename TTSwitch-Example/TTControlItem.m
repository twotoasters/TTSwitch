//
//  TTControlTableItem.m
//  TTSwitch
//
//  Created by Scott Penrose on 12/5/12.
//  Copyright (c) 2012 Two Toasters. All rights reserved.
//

#import "TTControlItem.h"

@implementation TTControlItem

+ (id)itemWithTitle:(NSString *)title control:(UIControl *)control
{
    TTControlItem *item = [[self alloc] init];
    item.title = title;
    item.control = control;
    return item;
}

@end
