//
//  TTControlCell.m
//  TTSwitch
//
//  Created by Scott Penrose on 12/5/12.
//  Copyright (c) 2012 Two Toasters. All rights reserved.
//

#import "TTControlCell.h"

#import "TTControlItem.h"

@implementation TTControlCell

#pragma mark - Init/Dealloc

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.clipsToBounds = NO;
        self.contentView.clipsToBounds = NO;
    }
    return self;
}

#pragma mark - Accessors

- (void)setControlItem:(TTControlItem *)controlItem
{
    _controlItem = controlItem;
    
    self.textLabel.text = _controlItem.title;
    self.accessoryView = _controlItem.control;
}

#pragma mark - UITableView Helpers

+ (NSString *)cellIdentifier
{
    return @"tt.switch.control.cellIdentifier";
}

@end
