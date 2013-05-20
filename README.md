# TTSwitch

*One switch to rule them all.*

TTSwitch is a UISwitch replacement built with images. You can now fully customize its appearance to whatever
you want. It also adds block support when the switch value is changed.
 
The switch also supports UIAppearance. You can globally setup all the TTSwitch appeareance and then anytime
you create an instance it will already be styled.

<img src="https://raw.github.com/twotoasters/TTSwitch/master/Resources/switches_on.png" height="50%" /> &nbsp;
<img src="https://raw.github.com/twotoasters/TTSwitch/master/Resources/switches_off.png" height="50%" />

## Getting Started

### Git submodule

Add the TTSwitch as a submodule to your project or download the code from the master branch [here](https://github.com/twotoasters/TTSwitch/archive/master.zip).

Simply add the TTSwitch.h + TTSwitch.m files in the TTSwitch folder to your Xcode project. Then `#include "TTSwitch.h"` in your source files where you want to use the TTSwitch.

### [CocoaPods](http://cocoapods.org/)

Add TTSwitch to your `Podfile` and `pod install`.

```ruby
pod 'TTSwitch', '~> 0.0.5'
```

## Resources

To make it easy to create your own custom switch we have included a [PSD](https://github.com/twotoasters/TTSwitch/raw/master/Resources/TTSwitch.psd) of the switches you see in the app. You are free to use these or make your own. You can also send this to your designer so that they will know how to design and cut the switches. We have also included a diagram of the layers of the switch so you can see how it is layed out.

<img src="https://raw.github.com/twotoasters/TTSwitch/master/Resources/switch_layers.png" height="328" width="560" />

## Example Usage

### UIAppearance

Globally setup the appeareance of all the TTSwitchs in your app.

```objc
[[TTSwitch appearance] setTrackImage:[UIImage imageNamed:@"round-switch-track"]];
[[TTSwitch appearance] setOverlayImage:[UIImage imageNamed:@"round-switch-overlay"]];
[[TTSwitch appearance] setTrackMaskImage:[UIImage imageNamed:@"round-switch-mask"]];
[[TTSwitch appearance] setThumbImage:[UIImage imageNamed:@"round-switch-thumb"]];
[[TTSwitch appearance] setThumbHighlightImage:[UIImage imageNamed:@"round-switch-thumb-highlight"]];
[[TTSwitch appearance] setThumbMaskImage:[UIImage imageNamed:@"round-switch-mask"]];
[[TTSwitch appearance] setThumbInsetX:-3.0f];
[[TTSwitch appearance] setThumbOffsetY:-3.0f];
```

### Default switch

```objc
TTSwitch *switch = [[TTSwitch alloc] initWithFrame:(CGRect){ CGPointZero, { 76.0f, 27.0f } }];
switch.trackImage = [UIImage imageNamed:@"square-switch-track"];
switch.overlayImage = [UIImage imageNamed:@"square-switch-overlay"];
switch.thumbImage = [UIImage imageNamed:@"square-switch-thumb"];
switch.thumbHighlightImage = [UIImage imageNamed:@"square-switch-thumb-highlight"];
```

### Switch with thumb bigger than track

```objc
TTSwitch *switch = [[TTSwitch alloc] initWithFrame:(CGRect){ CGPointZero, { 76.0f, 27.0f } }];
switch.trackImage = [UIImage imageNamed:@"square-switch-track"];
switch.overlayImage = [UIImage imageNamed:@"square-switch-overlay"];
switch.thumbImage = [UIImage imageNamed:@"square-switch-thumb"];
switch.thumbHighlightImage = [UIImage imageNamed:@"square-switch-thumb-highlight"];
switch.trackMaskImage = [UIImage imageNamed:@"square-switch-mask"];
switch.thumbOffsetY = -3.0f; // Set this to -3 to compensate for shadow 
```

### Switch with shadow on left and right of thumb that doesn't go outside of frame

```objc
TTSwitch *switch = [[TTSwitch alloc] initWithFrame:(CGRect){ CGPointZero, { 76.0f, 27.0f } }];
switch.trackImage = [UIImage imageNamed:@"round-switch-track"];
switch.overlayImage = [UIImage imageNamed:@"round-switch-overlay"];
switch.thumbImage = [UIImage imageNamed:@"round-switch-thumb"];
switch.thumbHighlightImage = [UIImage imageNamed:@"round-switch-thumb-highlight"];
switch.trackMaskImage = [UIImage imageNamed:@"round-switch-mask"];
switch.thumbMaskImage = [UIImage imageNamed:@"round-switch-mask"];
switch.thumbOffsetY = -3.0f; // Set this to -3 to compensate for shadow 
```

### Switch with labels for on/off text

```objc
TTSwitch *roundLabelSwitch = [[TTSwitch alloc] initWithFrame:(CGRect){ CGPointZero, { 76.0f, 28.0f } }];
// use normal setup and add
roundLabelSwitch.trackImage = [UIImage imageNamed:@"round-switch-track-no-text"];
roundLabelSwitch.labelsEdgeInsets = (UIEdgeInsets){ 3.0f, 10.0f, 3.0f, 10.0f };
roundLabelSwitch.onString = NSLocalizedString(@"ON", nil);
roundLabelSwitch.offString = NSLocalizedString(@"OFF", nil);
roundLabelSwitch.onLabel.textColor = [UIColor greenColor];
roundLabelSwitch.offLabel.textColor = [UIColor redColor];
```

## Credits

TTSwitch was created by [Scott Penrose](https://github.com/spenrose/)([@scottpenrose](http://twitter.com/scottpenrose)) and [Two Toasters](https://github.com/twotoasters)([@twotoasters](http://twitter.com/twotoasters)) in the development of [Go Try It On](http://www.gotryiton.com/).

## License

TTSwitch is available under the WTFPL. See the [LICENSE](https://github.com/twotoasters/TTSwitch/blob/master/LICENSE) file for more info.
