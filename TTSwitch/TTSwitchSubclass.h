//
//  TTSwitch+Subclass.h
//  TTSwitch
//
//  Created by Scott Penrose on 4/19/13.
//  Copyright (c) 2013 Two Toasters. All rights reserved.
//

#import "TTSwitch.h"

// the extensions in this header are to be used only by subclasses of TTSwitch
// code that uses TTSwitchs must never call these

@interface TTSwitch (ForSubclassEyesOnly)

@property (nonatomic, strong) UIImageView *trackImageView;
@property (nonatomic, strong) UIView *maskedTrackView;
@property (nonatomic, strong) UIImageView *thumbImageView;

/**
 Animates the thumb to the correct position for the switchs value.
 */
- (void)updateThumbPositionAnimated:(BOOL)animated;

/**
 Called during updateThumbPositionAnimated: when the thumb is animating on or off
 */
- (void)moveThumbCenterToX:(CGFloat)newThumbCenterX;

/**
 Called after the thumb has animated on or off in updateThumbPositionAnimated:
 */
- (void)didMoveThumbCenterToX:(CGFloat)newThumbCenterX;

/**
 Called when a user is panning the switch.
 */
- (void)handleThumbPanGesture:(UIPanGestureRecognizer *)gesture;

@end
