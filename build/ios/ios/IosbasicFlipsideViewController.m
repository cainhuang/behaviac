//
//  IosbasicFlipsideViewController.m
//  ios
//

#import "IosbasicFlipsideViewController.h"

@interface IosbasicFlipsideViewController ()

@end

@implementation IosbasicFlipsideViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Actions

- (IBAction)done:(id)sender
{
    [self.delegate flipsideViewControllerDidFinish:self];
}

@end
