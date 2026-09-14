import struct,sys,collections
p=sys.argv[1]
d=open(p,'rb').read()
pe=struct.unpack_from('<I',d,0x3c)[0]
mach,nsec,_,_,_,osz,_=struct.unpack_from('<HHIIIHH',d,pe+4)
opt=pe+24; so=opt+osz
secs=[]
for i in range(nsec):
    o=so+40*i
    secs.append((d[o:o+8].rstrip(b'\0').decode('latin1'),)+struct.unpack_from('<IIII',d,o+8))
def r2o(rva):
    for nm,vs,va,rs,ra in secs:
        if va<=rva<va+max(vs,rs): return ra+(rva-va)
    return None
nd=struct.unpack_from('<I',d,opt+92)[0]
dirs=[struct.unpack_from('<II',d,opt+96+8*i) for i in range(nd)]
imp=dirs[1][0]
o=r2o(imp)
tot=0
while True:
    olt,tstamp,fwd,namerva,fta=struct.unpack_from('<IIIII',d,o)
    if namerva==0: break
    no=r2o(namerva); dll=d[no:d.index(b'\0',no)].decode('latin1')
    t=r2o(olt or fta); fns=[]
    while True:
        e=struct.unpack_from('<I',d,t)[0]
        if e==0: break
        if e&0x80000000: fns.append('#%d'%(e&0xffff))
        else:
            no2=r2o(e)+2; fns.append(d[no2:d.index(b'\0',no2)].decode('latin1'))
        t+=4
    tot+=len(fns)
    print(f'== {dll} ({len(fns)})')
    print('   '+' '.join(sorted(fns)))
    o+=20
print('TOTAL imports',tot)
