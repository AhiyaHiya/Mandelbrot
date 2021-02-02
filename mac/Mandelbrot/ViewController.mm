//
//  ViewController.m
//  Mandelbrot
//
//  Created by Jaime Rios on 6/30/17.
//  Copyright © 2017 jaimerios.com. All rights reserved.
//

#import "ViewController.h"
#import "mandelbrot/mandelbrot.h"

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    NSImage* image = [self createMandelbrotImage];
    [_imageView setImage:image];
    //        [self setView:_imageView];
    [[self view] setNeedsDisplay:YES];
}

- (void)setRepresentedObject:(id)representedObject
{
    [super setRepresentedObject:representedObject];
}

- (NSImage*)createMandelbrotImage
{
    const NSRect rect    = [_imageView frame];
    const CGFloat margin = 20;
    const CGFloat width  = rect.size.width - margin;
    const CGFloat height = rect.size.height - margin;

    const NSUInteger channels = 4;

    const auto x_min = -2.0;
    const auto x_max = +0.5;
    const auto y_max = +1.0;
    const auto y_min = -1.0;

    auto pixels = jaimerios::create_vec_1d_filled_with_mandelbrot_pixels< unsigned char >(x_max, x_min, y_max, y_min, width, height);

    const auto                bits   = 8;
    unsigned char*            buff   = (unsigned char*)pixels.data();
    unsigned char* _Nullable* buffer = (unsigned char* _Nullable*)&buff;

    const NSInteger bpr = sizeof(unsigned char) * channels * width;
    const NSInteger bpp = sizeof(unsigned char) * bits * channels;

    NSBitmapImageRep* bitmap =
        [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:buffer
                                                pixelsWide:width
                                                pixelsHigh:height
                                             bitsPerSample:bits
                                           samplesPerPixel:channels
                                                  hasAlpha:YES
                                                  isPlanar:NO
                                            colorSpaceName:NSDeviceRGBColorSpace
                                               bytesPerRow:bpr
                                              bitsPerPixel:bpp];

    NSImage* image = [[NSImage alloc] init];
    [image addRepresentation:bitmap];

    return image;
}

@end
