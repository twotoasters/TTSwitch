//
//  TTDisplayViewController.m
//  TTSwitch
//
//  Created by Scott Penrose on 12/3/12.
//  Copyright (c) 2012 Two Toasters. All rights reserved.
//

#import "TTDisplayViewController.h"

#import "TTSwitch.h"

#import "TTControlItem.h"
#import "TTControlCell.h"

#import "TTXibViewController.h"

@interface TTDisplayViewController () <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, weak) UITableView *tableView;
@property (nonatomic, strong) NSArray *items;

@end

@implementation TTDisplayViewController

#pragma mark - UIViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"TTSwitch";
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Xib" style:UIBarButtonItemStyleBordered target:self action:@selector(openXib:)];
    
    UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    [tableView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
    [tableView setDelegate:self];
    [tableView setDataSource:self];
    [self.view addSubview:tableView];
    self.tableView = tableView;
    
    TTSwitch *defaultSwitch = [[TTSwitch alloc] initWithFrame:(CGRect){ CGPointZero, { 76.0f, 28.0f } }];
    // Default switch uses the appearance setup in AppDelegate
    
    TTSwitch *squareThumbSwitch = [[TTSwitch alloc] initWithFrame:(CGRect){ CGPointZero, { 76.0f, 27.0f } }];
    squareThumbSwitch.trackImage = [UIImage imageNamed:@"square-switch-track"];
    squareThumbSwitch.overlayImage = [UIImage imageNamed:@"square-switch-overlay"];
    squareThumbSwitch.thumbImage = [UIImage imageNamed:@"square-switch-thumb"];
    squareThumbSwitch.thumbHighlightImage = [UIImage imageNamed:@"square-switch-thumb-highlight"];
    squareThumbSwitch.trackMaskImage = [UIImage imageNamed:@"square-switch-mask"];
    squareThumbSwitch.thumbMaskImage = nil; // Set this to nil to override the UIAppearance setting
    squareThumbSwitch.thumbInsetX = -3.0f;
    squareThumbSwitch.thumbOffsetY = -3.0f; // Set this to -3 to compensate for shadow

    // Use on/off labels if you need to localize you switch
    TTSwitch *roundLabelSwitch = [[TTSwitch alloc] initWithFrame:(CGRect){ CGPointZero, { 76.0f, 28.0f } }];
    roundLabelSwitch.trackImage = [UIImage imageNamed:@"round-switch-track-no-text"];
    roundLabelSwitch.labelsEdgeInsets = (UIEdgeInsets){ 3.0f, 10.0f, 3.0f, 10.0f };
    roundLabelSwitch.onString = NSLocalizedString(@"ON", nil);
    roundLabelSwitch.offString = NSLocalizedString(@"OFF", nil);
    roundLabelSwitch.onLabel.textColor = [UIColor greenColor];
    roundLabelSwitch.offLabel.textColor = [UIColor redColor];
    
    self.items = @[
        [TTControlItem itemWithTitle:@"Round" control:defaultSwitch],
        [TTControlItem itemWithTitle:@"Square" control:squareThumbSwitch],
        [TTControlItem itemWithTitle:@"Labels" control:roundLabelSwitch],
    ];
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.items count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return [tableView dequeueReusableCellWithIdentifier:[TTControlCell cellIdentifier]] ? : [[TTControlCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[TTControlCell cellIdentifier]];
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    id item = self.items[indexPath.row];
    [((TTControlCell *)cell) setControlItem:item];
}

#pragma mark - Button Actions

- (void)openXib:(id)sender
{
    TTXibViewController *xibViewController = [[TTXibViewController alloc] initWithNibName:nil bundle:nil];
    [self.navigationController pushViewController:xibViewController animated:YES];
}

@end
