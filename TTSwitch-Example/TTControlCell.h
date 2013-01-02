//
//  TTControlCell.h
//  TTSwitch
//
//  Created by Scott Penrose on 12/5/12.
//  Copyright (c) 2012 Two Toasters. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TTControlItem;

@interface TTControlCell : UITableViewCell

@property (nonatomic, strong) TTControlItem *controlItem;

+ (NSString *)cellIdentifier;

@end
