// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2015 Intel Corporation. All Rights Reserved.
#pragma once

#include "proc/synthetic-stream.h"
#include <rsutils/concurrency/concurrency.h>
#include <vector>
#include <memory>
#include <map>
#include <mutex>
#include <atomic>


namespace librealsense
{
    class synthetic_source_interface;
    class frame_holder;

    namespace pipeline
    {
        class aggregator : public processing_block
        {
            std::mutex _mutex;
            std::map<int /*stream_id*/, frame_holder> _last_set;
            std::unique_ptr<single_consumer_frame_queue<frame_holder>> _queue;
            std::vector<int> _streams_to_aggregate_ids;
            std::vector<int> _streams_to_sync_ids;
            std::atomic<bool> _accepting;
            void handle_frame(frame_holder frame, synthetic_source_interface* source);
        public:
            aggregator(const std::vector<int>& streams_to_aggregate, const std::vector<int>& streams_to_sync);
            bool dequeue(frame_holder* item, unsigned int timeout_ms);
            bool try_dequeue(frame_holder* item);
            void start();
            void stop();
        };
    }
}
