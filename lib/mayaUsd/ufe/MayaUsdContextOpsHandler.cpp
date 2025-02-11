
//
// Copyright 2023 Autodesk
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include "MayaUsdContextOpsHandler.h"

#include <mayaUsd/ufe/MayaUsdContextOps.h>

namespace MAYAUSD_NS_DEF {
namespace ufe {

MayaUsdContextOpsHandler::MayaUsdContextOpsHandler()
    : UsdUfe::UsdContextOpsHandler()
{
}

MayaUsdContextOpsHandler::~MayaUsdContextOpsHandler() { }

/*static*/
MayaUsdContextOpsHandler::Ptr MayaUsdContextOpsHandler::create()
{
    return std::make_shared<MayaUsdContextOpsHandler>();
}

//------------------------------------------------------------------------------
// Ufe::ContextOpsHandler overrides
//------------------------------------------------------------------------------

Ufe::ContextOps::Ptr MayaUsdContextOpsHandler::contextOps(const Ufe::SceneItem::Ptr& item) const
{
    UsdSceneItem::Ptr usdItem = std::dynamic_pointer_cast<UsdSceneItem>(item);
#if !defined(NDEBUG)
    assert(usdItem);
#endif
    return MayaUsdContextOps::create(usdItem);
}

} // namespace ufe
} // namespace MAYAUSD_NS_DEF
