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

/**
 When switch is either fully on or off, mask the part of the track that is currently not showing. 
 The will mask from the center of the thumb to edge of switch. 
 Default = @YES
 */
@property (nonatomic, strong, getter = shouldMaskInLockPosition) NSNumber *maskInLockPosition UI_APPEARANCE_SELECTOR;

@property (nonatomic, assign, getter=isOn) BOOL on;

/**
 String for the on label.
*/
@property (nonatomic, copy) NSString *onString;

/**
 String for the off label.
 */
@property (nonatomic, copy) NSString *offString;

/** 
 Use this property to style the on label. It will only be added to the switch if you have set the
 text through the onString property.
 */
@property (nonatomic, strong, readonly) UILabel *onLabel;

/**
 Use this property to style the off label. It will only be added to the switch if you have set the
 text through the offString property.
 */
@property (nonatomic, strong, readonly) UILabel *offLabel;

/**
 Adjust positioning of labels. It uses the right and left edge insets for the horizontal postitioning of label. The top and bottom edge insets will
 be used to determine the height of the labels. Setting this will cause the labels to be added to the switch.
 */
@property (nonatomic, assign) UIEdgeInsets labelsEdgeInsets;

/**
 When the switch value is changed this block will be called.
 */
@property (nonatomic, copy) TTSwitchChangeHandler changeHandler;

/**
 When the switch value is changed this block will be called.
 @note This is here for autocompletion purposes. By explicitly declaring the mutator, the full block syntax will be autocompleted by Xcode.
 @param changeHandler Block that will be called on value change
 */
- (void)setChangeHandler:(TTSwitchChangeHandler)changeHandler;

/**
 A Boolean value that determines the off/on state of the switch.
 @param on the off/on state
 @param animated When changing the state of the switch should the switch animate to its new state
 */
- (void)setOn:(BOOL)on animated:(BOOL)animated;

@end
