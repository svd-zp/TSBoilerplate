/*
 Copyright (c) 2013 Tim Sawtell
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 IN THE SOFTWARE.
 */

#import <UIKit/UIKit.h>
#import "EGORefreshTableHeaderView.h"

#define IDIOM    UI_USER_INTERFACE_IDIOM()
#define IPAD     UIUserInterfaceIdiomPad

@interface TSViewController : UIViewController <EGORefreshTableHeaderDelegate, UIScrollViewDelegate, UITextFieldDelegate, UITextViewDelegate>

@property (nonatomic, strong) IBOutlet UIScrollView *scrollViewToResizeOnKeyboardShow;
@property (nonatomic, strong) EGORefreshTableHeaderView *headerView;
@property (nonatomic, strong) EGORefreshTableHeaderView *footerView;
@property (nonatomic) BOOL fetchingData;
@property (nonatomic) BOOL wantsPullToRefresh;
@property (nonatomic) BOOL wantsPullToRefreshFooter;
@property (nonatomic, strong) IBOutletCollection(UIControl) NSArray *inputFields;
@property (nonatomic, strong) UIProgressView *activityProgressView;

- (void)showActivityScreen;
- (void)showActivityScreenWithMessage:(NSString*)message;
- (void)hideActivityScreen;
- (void)reloadData; /** This will stop the pull to refresh (as in, time to show the new data) */
- (void)fetchData; /** This is called after pull to refresh has detected a request from the user */
- (CGSize)scrollViewContentSize; /* for when your scrollview is taller than your frame bounds and you need autolayout to not fuck it up */
- (void)doneLoadingData; /* to hide the pull to refresh views */
- (void)pullUpAction;
- (void)pullDownAction;
@end
