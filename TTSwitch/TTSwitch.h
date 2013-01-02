//
//  TTSwitch.h
//  TTSwitch
//
//  Created by Scott Penrose on 12/3/12.
//  Copyright (c) 2012 Two Toasters. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^TTSwitchChangeHandler)(BOOL on);

/**
 TTSwitch is a UISwitch replacement built with images. You can now fully customize its appearance to whatever
 you want. It also adds block support when the switch value is changed.
 
 The switch is either on or off. When the value changes you can provide a block to be executed. A
 UIControlEventValueChanged event will also be fired right after the block is executed.
 
 The switch also supports UIAppearance. You can globally setup all the TTSwitch appeareance and then anytime
 you create an instance it will already be styled.
 */
@interface TTSwitch : UIControl

@property (nonatomic, strong) UIImage *trackImage UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *overlayImage UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *thumbImage UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *thumbHighlightImage UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIImage *trackMaskImage UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *thumbMaskImage UI_APPEARANCE_SELECTOR;

/**
 If the thumb image has a shadow you will need to add an inset to make it sit flush when fully on or off.
 */
@property (nonatomic, assign) CGFloat thumbInsetX UI_APPEARANCE_SELECTOR;

/**
 Adjust the vertical positioning of the thumb
 */
@property (nonatomic, assign) CGFloat thumbOffsetY UI_APPEARANCE_SELECTOR;

@property (nonatomic, assign, getter=isOn) BOOL on;

/**
 When the switch value is changed this block will be called.
 */
@property (nonatomic, copy) TTSwitchChangeHandler changeHandler;

/**
 A Boolean value that determines the off/on state of the switch.
 @param on the off/on state
 @param animated When changing the state of the switch should the switch animate to its new state
 */
- (void)setOn:(BOOL)on animated:(BOOL)animated;

@end
