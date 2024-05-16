# automatically generated by the FlatBuffers compiler, do not modify

# namespace: tflite

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class LeakyReluOptions(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsLeakyReluOptions(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = LeakyReluOptions()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def LeakyReluOptionsBufferHasIdentifier(cls, buf, offset, size_prefixed=False):
        return flatbuffers.util.BufferHasIdentifier(buf, offset, b"\x54\x46\x4C\x33", size_prefixed=size_prefixed)

    # LeakyReluOptions
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # LeakyReluOptions
    def Alpha(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float32Flags, o + self._tab.Pos)
        return 0.0

def LeakyReluOptionsStart(builder): builder.StartObject(1)
def LeakyReluOptionsAddAlpha(builder, alpha): builder.PrependFloat32Slot(0, alpha, 0.0)
def LeakyReluOptionsEnd(builder): return builder.EndObject()
