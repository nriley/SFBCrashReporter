/*
 *  Copyright (C) 2009, 2010, 2011, 2012, 2013, 2014, 2015 Stephen F. Booth <me@sbooth.org>
 *  All Rights Reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Cocoa/Cocoa.h>

// ========================================
// The main class for SFBCrashReporter
// ========================================
@interface SFBCrashReporterWindowController : NSWindowController
{}

// ========================================
// Properties
@property (nonatomic, strong, nullable) NSString * emailAddress;
@property (nonatomic, strong, nonnull) NSString * crashLogPath;
@property (nonatomic, strong, nonnull) NSURL * submissionURL;

// ========================================
// IB Outlets
@property (nonatomic, assign, nonnull) IBOutlet NSTextView * commentsTextView; // weak property type not available for NSTextView
@property (nonatomic, weak) IBOutlet NSComboBox * emailAddressesComboBox;
@property (nonatomic, weak) IBOutlet NSButton * reportButton;
@property (nonatomic, weak) IBOutlet NSButton * ignoreButton;
@property (nonatomic, weak) IBOutlet NSButton * discardButton;
@property (nonatomic, weak) IBOutlet NSProgressIndicator * progressIndicator;

// ========================================
// Always use this to show the window- do not alloc/init directly
+ (void) showWindowForCrashLogPath:(nonnull NSString *)path submissionURL:(nonnull NSURL *)submissionURL;

// ========================================
// Action methods
- (IBAction) sendReport:(nullable id)sender;
- (IBAction) ignoreReport:(nullable id)sender;
- (IBAction) discardReport:(nullable id)sender;

@end
