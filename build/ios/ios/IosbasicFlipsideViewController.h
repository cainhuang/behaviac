//
//  IosbasicFlipsideViewController.h
//  ios
//

#import <UIKit/UIKit.h>

@class IosbasicFlipsideViewController;

@protocol IosbasicFlipsideViewControllerDelegate
- (void)flipsideViewControllerDidFinish:(IosbasicFlipsideViewController *)controller;
@end

@interface IosbasicFlipsideViewController : UIViewController

@property (weak, nonatomic) id <IosbasicFlipsideViewControllerDelegate> delegate;

- (IBAction)done:(id)sender;

@end
