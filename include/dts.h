#ifndef HAVE_DTS_H
#define HAVE_DTS_H
#include "common.h"

/* Local */

#include "stringblock.h"

/* Definition */

#define DTS_BEGIN_NODE_SPEC     0x00000001U
#define DTS_END_NODE_SPEC       0x00000002U
#define DTS_PROP_SPEC           0x00000003U
#define DTS_NOP_SPEC            0x00000004U
#define DTS_END_SPEC            0x00000009U

#define DTS_BEGIN_NODE_ACTUAL   0x01000000U
#define DTS_END_NODE_ACTUAL     0x02000000U
#define DTS_PROP_ACTUAL         0x03000000U
#define DTS_NOP_ACTUAL          0x04000000U
#define DTS_END_ACTUAL          0x09000000U

/* Structure */

struct 
    dts_partition_entry {
        char        name[MAX_PARTITION_NAME_LENGTH];
        uint64_t    size;
        uint32_t    mask;
        uint32_t    phandle;
        uint32_t    linux_phandle;
    };

struct 
    dts_partitions_helper {
        struct dts_partition_entry  partitions[MAX_PARTITIONS_COUNT];
        uint32_t                    phandle_root;
        uint32_t                    linux_phandle_root;
        uint32_t                    phandles[MAX_PARTITIONS_COUNT];
        uint32_t                    partitions_count;
        uint32_t                    record_count;
    };

struct 
    dts_phandle_list {
        uint8_t *   phandles;
        uint32_t    min_phandle;
        uint32_t    max_phandle;
        uint32_t    allocated_count;
        bool        have_linux_phandle;
    };

/* Function */

uint8_t *
    dts_get_node_from_path(
        const uint8_t * dts, 
        uint32_t        max_offset,
        const char *    path,
        size_t          len_path
    );

struct dts_partitions_helper *
    dts_get_partitions_from_node(
        const uint8_t *                     node,
        const struct stringblock_helper *   shelper
    );

uint32_t 
    dts_get_phandles_recursive(
        const uint8_t *             node, 
        uint32_t                    max_offset,
        uint32_t                    offset_phandle,
        uint32_t                    offset_linux_phandle,
        struct dts_phandle_list *   plist
    );

int 
    dts_phandle_list_finish(
        struct dts_phandle_list *   plist
    );

void
    dts_report_partitions(
        const struct dts_partitions_helper *    phelper
    );

int
    dts_sort_partitions(
        struct dts_partitions_helper *  phelper
    );
#endif