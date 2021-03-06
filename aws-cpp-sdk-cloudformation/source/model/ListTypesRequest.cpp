﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/cloudformation/model/ListTypesRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::CloudFormation::Model;
using namespace Aws::Utils;

ListTypesRequest::ListTypesRequest() : 
    m_visibility(Visibility::NOT_SET),
    m_visibilityHasBeenSet(false),
    m_provisioningType(ProvisioningType::NOT_SET),
    m_provisioningTypeHasBeenSet(false),
    m_deprecatedStatus(DeprecatedStatus::NOT_SET),
    m_deprecatedStatusHasBeenSet(false),
    m_maxResults(0),
    m_maxResultsHasBeenSet(false),
    m_nextTokenHasBeenSet(false)
{
}

Aws::String ListTypesRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=ListTypes&";
  if(m_visibilityHasBeenSet)
  {
    ss << "Visibility=" << VisibilityMapper::GetNameForVisibility(m_visibility) << "&";
  }

  if(m_provisioningTypeHasBeenSet)
  {
    ss << "ProvisioningType=" << ProvisioningTypeMapper::GetNameForProvisioningType(m_provisioningType) << "&";
  }

  if(m_deprecatedStatusHasBeenSet)
  {
    ss << "DeprecatedStatus=" << DeprecatedStatusMapper::GetNameForDeprecatedStatus(m_deprecatedStatus) << "&";
  }

  if(m_maxResultsHasBeenSet)
  {
    ss << "MaxResults=" << m_maxResults << "&";
  }

  if(m_nextTokenHasBeenSet)
  {
    ss << "NextToken=" << StringUtils::URLEncode(m_nextToken.c_str()) << "&";
  }

  ss << "Version=2010-05-15";
  return ss.str();
}


void  ListTypesRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
