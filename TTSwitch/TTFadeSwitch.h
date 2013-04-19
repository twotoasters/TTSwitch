//
//  TTFadeSwitch.h
//  TTSwitch
//
//  Created by Scott Penrose on 4/19/13.
//  Copyright (c) 2013 Two Toasters. All rights reserved.
//

#import "TTSwitch.h"

@interface TTFadeSwitch : TTSwitch

@property (nonatomic, strong) UIImage *trackImage UI_APPEARANCE_SELECTOR;// __attribute__((unavailable("Only available on TTSwitch. Use trackImageOn and trackImageOff on TTFadeSwitch.")));

@property (nonatomic, strong) UIImage *trackImageOn UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *trackImageOff UI_APPEARANCE_SELECTOR;

@end
