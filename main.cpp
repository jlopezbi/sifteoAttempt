#include <sifteo.h>
using namespace Sifteo;

static const unsigned gNumCubes = 3;

static Metadata M = Metadata()
    .title("Accelerometer Chart")
    .package("com.sifteo.extras.accelchart", "0.1")
    .cubeRange(1,3);



class Squiggle{
public:
    void init(CubeID cube)
    {
        frame = 0;
        const unsigned ticksPerPixel = 50;
        vid.initMode(FB64);
        vid.colormap[0] = 0xdddddd;
        vid.colormap[1] = 0x000088;
        vid.attach(cube);
    }
    
    void update(TimeDelta TimeStep)
    {
        unsigned y = 10;
        unsigned x1 = 3;
        unsigned x2 = 10;
        vid.fb64.span(vec(x1,y),x2-x1, 1);
        vid.fb64.fill(vec(x2,y),vec(x2,y),1);
        
        
        /*while (iter.next()) {
            while (iter.ticks() >= ticksPerPixel) {
            iter.adjustTicks(-ticksPerPixel);
            
            int x = clamp(32 + iter.accel().y / 2, 0, 63);
            
            // Draw a line from old X to new X
            int x1 = MIN(x, prevX+1);
            int x2 = MAX(x, prevX-1);
            vid.fb64.span(vec(x1,y), x2-x1+1, 1);
            prevX = x;
            
            // Erase one row ahead
            if (++y == 64) y = 0;
            vid.fb64.span(vec(0,y), 64, 0);
        }
    }*/
        
        
    }
private:
    
    VideoBuffer vid;
    unsigned frame;
    float fpsTimespan;
    
    
    
};

void main()
{
    
    static Squiggle instances[gNumCubes];
    
    for(unsigned i = 0; i< arraysize(instances);i++)
        instances[i].init(i);
    
    TimeStep ts;
    
    
    while (1) {
        
        for(unsigned i =0; i<arraysize(instances);i++)
            instances[i].update(ts.delta());
        System::paint();
        ts.next();
        
        
    }
}