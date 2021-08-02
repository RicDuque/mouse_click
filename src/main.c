#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int x = 900;
    int y = 500;

    if (argc == 3) {
        printf("提供される引数は「%s」と「%s」です\n", argv[1], argv[2]);
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }
    else if (argc > 3) {
        printf("提供された引数が多すぎます\n");
    }

    for (int i = 0; i < 180; i ++) {
        // Move to 200x200
        CGEventRef move1 = CGEventCreateMouseEvent(
            NULL, kCGEventMouseMoved,
            CGPointMake(x, y),
            kCGMouseButtonLeft // ignored
        );
        // Left button down at 250x250
        CGEventRef click1_down = CGEventCreateMouseEvent(
            NULL, kCGEventLeftMouseDown,
            CGPointMake(x, y),
            kCGMouseButtonLeft
        );
        // Left button up at 250x250
        CGEventRef click1_up = CGEventCreateMouseEvent(
            NULL, kCGEventLeftMouseUp,
            CGPointMake(x, y),
            kCGMouseButtonLeft
        );
        // Now, execute these events with an interval to make them noticeable
        CGEventPost(kCGHIDEventTap, move1);
        CGEventPost(kCGHIDEventTap, click1_down);
        CGEventPost(kCGHIDEventTap, click1_up);
        CFRelease(click1_up);
        CFRelease(click1_down);
        sleep(3);

    }
    return 0;
}

/*
int main() {
    // Move to 200x200
    CGEventRef move1 = CGEventCreateMouseEvent(
        NULL, kCGEventMouseMoved,
        CGPointMake(200, 200),
        kCGMouseButtonLeft // ignored
    );
    // Move to 250x250
    CGEventRef move2 = CGEventCreateMouseEvent(
        NULL, kCGEventMouseMoved,
        CGPointMake(250, 250),
        kCGMouseButtonLeft // ignored
    );
    // Left button down at 250x250
    CGEventRef click1_down = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseDown,
        CGPointMake(250, 250),
        kCGMouseButtonLeft
    );
    // Left button up at 250x250
    CGEventRef click1_up = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseUp,
        CGPointMake(250, 250),
        kCGMouseButtonLeft
    );
    // Now, execute these events with an interval to make them noticeable
    CGEventPost(kCGHIDEventTap, move1);
    sleep(1);
    CGEventPost(kCGHIDEventTap, move2);
    sleep(1);
    CGEventPost(kCGHIDEventTap, click1_down);
    CGEventPost(kCGHIDEventTap, click1_up);
    // Release the events
    CFRelease(click1_up);
    CFRelease(click1_down);
    CFRelease(move2);
    CFRelease(move1);
        return 0;
}
*/
