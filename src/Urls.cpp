// Copyright 2019 Caffeine Inc. All rights reserved.

#include "Urls.hpp"
#include <stdlib.h>
#include "Utils.hpp"

namespace caff {

    const std::string caffeineDomain = []() -> std::string {
        auto custom = getenv("LIBCAFFEINE_DOMAIN");
        if (!isEmpty(custom)) {
            return custom;
        }
        return "caffeine.tv";
    }();

    std::string const apiEndpoint = "https://api." + caffeineDomain;
    std::string const realtimeEndpoint = "https://realtime." + caffeineDomain;
    std::string const eventsEndpoint = "https://events." + caffeineDomain;

    std::string const versionCheckUrl = apiEndpoint + "/v1/version-check";
    std::string const signInUrl = apiEndpoint + "/v1/account/signin";
    std::string const refreshTokenUrl = apiEndpoint + "/v1/account/token";
    std::string const getGamesUrl = apiEndpoint + "/v1/games";

    std::string const realtimeGraphqlUrl = realtimeEndpoint + "/public/graphql/query";

    std::string const broadcastMetricsUrl = eventsEndpoint + "/v1/broadcast_metrics";

    std::string getUserUrl(std::string const & id) { return apiEndpoint + "/v1/users/" + id; }

    std::string broadcastUrl(std::string const & id) { return apiEndpoint + "/v1/broadcasts/" + id; }

    std::string streamHeartbeatUrl(std::string const & streamUrl) { return streamUrl + "/heartbeat"; }

} // namespace caff
